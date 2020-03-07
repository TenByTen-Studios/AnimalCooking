#include "IngredientMotion.h"
#include "IngredientsPool.h"
#include "Entity.h"

void IngredientMotion::init() {
	pool_ = GETCMP1_(IngredientsPool)->getPool();
}

void IngredientMotion::draw() {
	for (Ingredient* b : pool_) {
		cout << "b";
		if (b->inUse()) {
			b->update();
		}
	}
}