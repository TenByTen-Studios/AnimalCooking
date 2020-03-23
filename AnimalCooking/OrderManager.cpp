#include "OrderManager.h"
#include "FoodDictionary.h"

OrderManager::OrderManager() : OrderManager(2)
{
}

OrderManager::OrderManager(size_t maxOrders) : Component(ecs::OrderManager),
		currentOrders_(maxOrders, nullptr), products_(maxOrders, Resources::FoodType::Empty),
		distXBetweenOrders_(50)
{
}

OrderManager::~OrderManager()
{
	for (auto o : currentOrders_) {
		delete o;
	}
}

//void OrderManager::update()
//{
//	for (auto o : currentOrders_) {
//		if (o != nullptr) o->update();
//	}
//}

void OrderManager::setMaxOrders(size_t size)
{
	currentOrders_.resize(size, nullptr);
	products_.resize(size, Resources::FoodType::Empty);
}

void OrderManager::addOrder(Resources::FoodType finalProduct)
{
	auto it = getFreePos();
	if (it != currentOrders_.end()) { //Si hay hueco se mete el pedido, y si no hay, el cliente se va

		set<int> ings_ = FoodDictionary::instance()->getIngsForFood(finalProduct); //Recibe los ingredientes que usa ese pedido

		if (!ings_.empty()) {

			//Vector de texturas
			vector<Texture*> texturesIngs_;
			for (auto i : ings_) {				//el id de Resources::FoodType debe coincidir con el de Resources::Textures
				texturesIngs_.push_back(game_->getTextureMngr()->getTexture(i)); 
			}

			//Mete el pedido
			*it = new Order( //Mete un order en la posicion libre			 

				//Se asigna la posicion a los orders aqui, pero tal vez deberia ser el OrderViewer

				Vector2D(100 + distXBetweenOrders_ * (it - currentOrders_.begin()), 700), // pos en x es relativa a su posicion en el vector
				game_->getTextureMngr()->getTexture(finalProduct), // OrderText
				texturesIngs_ // ingsText
			);

			//Asigna el producto que obtendria del pedido en un vector auxiliar
			products_.at(it - currentOrders_.begin()) = finalProduct; //Asigno en la posicion del pedido que pedido es
		}
	}
}

void OrderManager::removeOrder(Resources::FoodType finalProduct)
{
	auto it = getIndexOf(finalProduct);
	if (it != currentOrders_.end()) { //Si encuentra el producto a eliminar, elimina el pedido
		delete *it; 
		*it = nullptr;

		// Anadir puntos al ScoreManager
	}
}

vector<Order*>& OrderManager::getOrders()
{
	return currentOrders_;
}

vector<Order*>::iterator OrderManager::getFreePos()
{
	auto it = currentOrders_.begin();
	while (it != currentOrders_.end()) {
		if (*it == nullptr) break; //Paro la busqueda cuando encuentro una posicion libre
		++it;
	}
	return it;
}

vector<Order*>::iterator OrderManager::getIndexOf(Resources::FoodType finalProduct)
{
	vector<Order*>::iterator it = currentOrders_.begin();
	while (it != currentOrders_.end()) {
		if (products_.at(it - currentOrders_.begin()) == finalProduct) break; //Paro la busqueda cuando encuentro el pedido de finalProduct
		++it;
	}
	return it;
}
