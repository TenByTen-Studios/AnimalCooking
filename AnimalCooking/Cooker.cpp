#include "Cooker.h"
#include "SDLGame.h"
#include "SDL_macros.h"
#include "InsertExpel.h"
#include "TimerViewer.h"

Cooker::Cooker(Vector2D& pos, Vector2D& size, double rot, Texture* text, Transport* t1, Transport* t2,Entity* e) : Interactive(t1,t2,nullptr),
	state_(CookerStates::empty), cookingTime_(5),entity_(e), timer_(nullptr)
{
	setPos(pos);
	setSize(size);
	setRot(rot);
	setEmptyTexture();

	feedbackVisual_ = SDLGame::instance()->getTextureMngr()->getTexture(Resources::Panel);
}

void Cooker::initTimer()
{
	timer_ = new CookerTimer(cookingTime_ * 1000);

	timer_->setPos(Vector2D((position_.getX() + size_.getX()/2) - timer_->getSize().getX()/2, 
		(position_.getY() + size_.getY()/2) - timer_->getSize().getY()/2));
	GETCMP2(SDLGame::instance()->getTimersViewer(), TimerViewer)->addTimer(timer_);
}

Cooker::~Cooker() {
	timer_ = nullptr;
}

void Cooker::setCookerState(CookerStates s) { 
	switch (s) {
		case CookerStates::empty:  setEmptyTexture(); break;
		case CookerStates::cooking: setCookingTexture(); break;
		case CookerStates::cooked:  setCookedTexture(); break;
		case CookerStates::burned:  setBurnedTexture(); break;
	}
	state_ = s; 
};

void Cooker::draw()
{
	SDL_Rect rect = RECT(position_.getX(), position_.getY(), size_.getX(), size_.getY());

	texture_->render(rect, rotation_); //Cambiar para usar animaciones
}

void Cooker::action1(int player)
{
	InsertExpel* ie = entity_->getComponent<InsertExpel>(ecs::InsertExpel);
	if (this->getCookerState() == CookerStates::empty)
	{
		ie->insertFood(this);
	}
	else 
	{
		ie->extractFood(this, timer_);
	}
}

void Cooker::feedback(int player)
{
	if (state_ != CookerStates::empty) {
		int ofset = 60;
		int offsetInside = 15;
		int rows = ceil(foods_.size() / 2.0);
		if (rows == 0) rows = 1;

		int w = 190/ 2 - offsetInside * 2;
		SDL_Rect rect = RECT(position_.getX() + ofset, position_.getY() + ofset, 190, rows*w + offsetInside*2);
		feedbackVisual_->render(rect);
		rect.x += offsetInside;
		rect.y += offsetInside;

		for (int i = 0; i < foods_.size(); ++i) {

			SDL_Rect r = { rect.x + w * (i % 2), rect.y + w * (i / 2), w, w };
			foods_[i]->draw(r);
		}
	}
}

Skillet::Skillet(Vector2D& pos, Vector2D& size, double rot, Texture* text,Transport* t1,Transport* t2, Entity* e) : Cooker(pos, size, rot, text,t1,t2,e)
{
	cookingTime_ = 10 * 1000;
	cookerType_ = Resources::Cookers::Skillet;
	initTimer();
}

Oven::Oven(Vector2D& pos, Vector2D& size, double rot, Texture* text, Transport* t1, Transport* t2, Entity* e) : Cooker(pos, size, rot, text,t1,t2,e)
{
	cookingTime_ = 15 * 1000;
	cookerType_ = Resources::Cookers::Oven;
	initTimer();
}