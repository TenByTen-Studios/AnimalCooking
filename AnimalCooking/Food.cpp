#include "Food.h"
#include "SDL_macros.h"

Food::Food(Vector2D position, Resources::FoodType type, Transport* p1, Transport* p2) : Pickable(p1, p2)
{
	timer_ = FoodTimer();
	position_ = position;
	size_ = Vector2D(64, 64);
	type_ = type;
	foodPool_ = nullptr;
	speed_ = Vector2D();
}

Food::Food(Resources::FoodType type) : Pickable(nullptr, nullptr) {
	position_ = Vector2D();
	size_ = Vector2D(50, 50);
	type_ = type;
	foodPool_ = nullptr;
	speed_ = Vector2D();
}

void Food::setFoodPool(FoodPool* foodPool, std::vector<Food*>::iterator it)
{
	foodPool_ = foodPool;
	iterator_ = it;
}

void Food::Destroy()
{
	foodPool_->RemoveFood(iterator_);
}

void Food::update()
{
	Pickable::update();

	if (timer_.isTimerEnd()) {
		foodPool_->RemoveFood(iterator_);
	}
	else {
		timer_.update();
	}
}

void Food::onDrop(bool onFloor)
{
	if (onFloor) {
		Pickable::onDrop(onFloor);
		timer_.timerStart();
	}
}

void Food::action1(int player)
{
	if (player == Resources::Player1) {
		player1_->pick(this, Resources::PickableType::Food);
	}
	else {
		player2_->pick(this, Resources::PickableType::Food);
	}
}
void Food::onPick() {
	timer_.timerReset();
}


