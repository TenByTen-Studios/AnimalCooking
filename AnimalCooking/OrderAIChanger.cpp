#include "OrderAIChanger.h"
#include "AIClient.h"
#include "Entity.h"

OrderAIChanger::OrderAIChanger(const initializer_list<int>& times, TimerViewer* tv) : Component(ecs::OrderAIChanger),
	groups_(), aiClient_(nullptr), timer(nullptr), times_(times) 
{
	groups_.push({ Resources::FoodType::Salad, Resources::FoodType::Roast3 });
	groups_.push({ Resources::FoodType::RiceDish, Resources::FoodType::Rice2 });
	groups_.push({ Resources::FoodType::IcedCookedFish, Resources::FoodType::Teriyaki4 });
	groups_.push({ Resources::FoodType::Pizza, Resources::FoodType::Perrito3 });

	timer = new Timer();
	timer->setTime(times_.front() * 1000); times_.pop();
	tv->addTimer(timer);
}

void OrderAIChanger::init()
{
	aiClient_ = GETCMP1_(AIClient);
	aiClient_->changeOrderGroup(groups_.front()); 
	groups_.pop();
}

void OrderAIChanger::update()
{
	timer->update();
	if (timer->isTimerEnd()) {
		if (!groups_.empty()) { 
			aiClient_->changeOrderGroup(groups_.front());
			groups_.pop(); 
		}
		if (!times_.empty()) {
			timer->setTime(times_.front() * 1000); times_.pop();
			timer->timerReset();
			timer->timerStart();
		}
	}
}
