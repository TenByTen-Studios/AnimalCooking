#include "InsertExpel.h"
#include <list>

InsertExpel::InsertExpel(Transport* tr) :
	Component(ecs::InsertExpel),
	transport_(tr),
	foodCooker_(nullptr)
{
}

InsertExpel::InsertExpel() :
	Component(ecs::InsertExpel),
	foodCooker_(nullptr),
	transport_(nullptr)
{
}

InsertExpel::~InsertExpel() {	
}

void InsertExpel::init() {
	foodCooker_ = GETCMP1_(FoodCooker);
}

//void InsertExpel::insertFood(Cooker *c, list<Food*>& f) {
//	//Terminar de perfilar comportamiento cuando se haya hecho Transport (para saber si tiene plato y quitarlo del vector del plato o quitarlo de la mano del player en caso de que se ponga esa acci�n)
//	//Por ahora solo se programa el comportamiento para sacarlo de un plato (supuesto caso en que un player lleve comida dentro de un plato y quiera meterlo a un cocinador)
//	//if (transport_.getEmptyDish()) {
//		if (c->getCookerState() == CookerStates::empty) {
//			c->getFoods().insert(c->getFoods().end(), f.begin(), f.end());
//				//poner borrado del elemento en el vector del transport
//			f.clear();
//			c->setCookerState(CookerStates::cooking);
//			c->getCookerTimer()->setTime(c->getCookingTime());
//			c->getCookerTimer()->timerStart();
//		}
//	//}
//}

void InsertExpel::insertFood(Cooker* c) {
	//Terminar de perfilar comportamiento cuando se haya hecho Transport (para saber si tiene plato y quitarlo del vector del plato o quitarlo de la mano del player en caso de que se ponga esa acci�n)
	//Por ahora solo se programa el comportamiento para sacarlo de un plato (supuesto caso en que un player lleve comida dentro de un plato y quiera meterlo a un cocinador)
	if (transport_.hasEmptyDish()) {
		if (c->getCookerState() == CookerStates::empty) {
			Dish* dish_ = static_cast<Dish*>(transport_.getObjectInHands());
			c->getFoods().insert(c->getFoods().end(), dish_->getFoodVector().begin(), dish_->getFoodVector().end());
			dish_->.getFoodVector().clear();
			foodCooker_->startCooked(c);
		}
	}
}
//
//void InsertExpel::extractFood(Cooker *c, int foodSelectorPosition) {
//	//Terminar de perfilar comportamiento cuando se haya hecho Transport (para saber si tiene plato y quitarlo del vector del plato o quitarlo de la mano del player en caso de que se ponga esa acci�n)
//	//Por ahora solo se programa el comportamiento para sacarlo de un plato (supuesto caso en que un player lleve comida dentro de un plato y quiera meterlo a un cocinador)
//	if (/*transport_.getEmptyDish() &&*/ c->getCookerState() == CookerStates::cooked || c->getCookerState() == CookerStates::burned) {
//		//transport_.getItem().getVector().insert(transport_.getItem().getVector().end(), c->getFoods()[foodSelectorPosition]);
//		//poner borrado del elemento en el vector del cooker
//		c->setCookerState(CookerStates::empty);
//	}
//}

void InsertExpel::extractAllFood(Cooker *c){
	//Terminar de perfilar comportamiento cuando se haya hecho Transport (para saber si tiene plato y quitarlo del vector del plato o quitarlo de la mano del player en caso de que se ponga esa acci�n)
	//Por ahora solo se programa el comportamiento para sacarlo de un plato (supuesto caso en que un player lleve comida dentro de un plato y quiera meterlo a un cocinador)
	if (transport_.hasEmptyDish() && c->getCookerState() != CookerStates::empty) {
		Dish* dish_ = static_cast<Dish*>(transport_.getObjectInHands());
		dish_->getFoodVector().insert(dish_->getFoodVector().end(), c->getFoods().begin(), c->getFoods().end())
		c->getFoods().clear();
		c->setCookerState(CookerStates::empty);
	}
}