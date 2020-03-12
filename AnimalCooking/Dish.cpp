#include "Dish.h"

Dish::Dish(Vector2D pos_)
{
	pos = pos_;
	width = 100;
	height = 50;
	vel = Vector2D(10, 10);
}

// si la lista estaba vacía pone el iterador al principio
void Dish::addFood(Food* f)
{
	if (f != nullptr) {
		foods_.push_back(f);
		if (foods_.size() == 1)
		{
			currentFood = foods_.begin();
		}
	}

}

Food* Dish::takeFood()
{//si la lista no se ha vaciado pone el iterador al principio para evitar errores
	if (!foods_.empty()) {
		Food* aux = *currentFood;
		foods_.remove(*currentFood);
		if (!foods_.empty())
			currentFood = foods_.begin();
		return aux;
	}
	else return nullptr;
}
//Comprobamos que no está la lista vacía y no se ha llegado al último elemento
void Dish::nextFood() {
	if (!foods_.empty() && currentFood != (--foods_.end()))
		currentFood++;
}
//Comprobamos que no está la lista vacía y no estamos en el primer elemento
void Dish::previousFood() {
	if (!foods_.empty() && currentFood != foods_.begin())
		currentFood--;
}
void Dish::render() {
	int k = 0;
	//Colocamos la comida en el centro del plato y un poco más arriba del fondo del plato
	//(teniendo en cuenta el índice la comida) y renderizamos
	for (auto i = foods_.begin(); i != foods_.end(); i++)
	{
		(*i)->setPosition(Vector2D(pos.getX() + (*i)->getSize().getX() / 2,
			pos.getY() - (*i)->getSize().getY() / 4 - (int64_t)((*i)->getSize().getY() * k)));
		(*i)->draw();
		k++;
	}
}

void Dish::update()
{
	pos = pos + vel;
}