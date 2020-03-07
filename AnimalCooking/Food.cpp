#include "Food.h"

Food::Food()
{
	foodPool_ = nullptr;
}

void Food::setFoodPool(FoodPool* foodPool)
{
	foodPool_ = foodPool;
	iterator_ = --foodPool->getPool()->end();
}

void Food::Destroy()
{
	foodPool_->getPool()->erase(iterator_);
}

void Food::update()
{
	position_ = position_ + dir_;
}