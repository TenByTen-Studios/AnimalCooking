#include "Dish.h"

Dish::Dish(Vector2D pos_, Transport* transPlayer1, Transport* transPlayer2,int maxFood, FoodPool* fp) : Pickable(transPlayer1, transPlayer2),foods_(vector<Food*>()),isViewingContent(false),inHands(true),foodPool(fp)
{
	foods_.reserve(maxFood);
}

// si el vector estaba vacío pone el iterador al principio
void Dish::addFood(Food* f)
{
	if (f != nullptr) 
	{
		foods_.emplace_back(f);			
		currentFood = ++(foods_.rbegin());		
	}
}

Food* Dish::takeFood()
{
	//si el vector no se ha vaciado pone el iterador al principio para evitar errores
	if (!foods_.empty()) 
	{
		Food* aux = *currentFood.base();
		foods_.erase(currentFood.base());
		if (!foods_.empty())
			currentFood = ++(foods_.rbegin());
		return aux;
	}
	else return nullptr;
}
//Comprobamos que no está el vector vacío y no se ha llegado al último elemento
void Dish::nextFood() 
{
	if (!foods_.empty() && isViewingContent && currentFood != foods_.rend())
		currentFood++;
	cout << (*currentFood.base())->getType();
}
//Comprobamos que no está el vector vacío y no estamos en el primer elemento
void Dish::previousFood() 
{
	if (!foods_.empty() && isViewingContent && currentFood != ++(foods_.rbegin()))
		currentFood--;
	cout << (*currentFood)->getType();
}



void Dish::firstFood()
{
	currentFood = ++(foods_.rbegin());
	if(!foods_.empty())cout << (*currentFood.base())->getType();

}

void Dish::clearFoods()
{	
	auto it = foods_.begin();
	while (it != foods_.end()) {
		delete* it;		
		++it;
	}
	foods_.clear();
	foodPool->getPool().clear();
}
