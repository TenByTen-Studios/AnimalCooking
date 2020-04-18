#include "Transport.h"
#include "Entity.h"
#include "Dish.h"

Transport::Transport() : Component(ecs::Transport),
objInHands_(nullptr),
playerTransform_(nullptr),
objType_(objType_ = Resources::PickableType::none)
{
}

void Transport::pick(Pickable* obj, Resources::PickableType objType, bool inFloor)
{
	if (objInHands_ == nullptr) {
		objInHands_ = obj;
		objType_ = objType;
	}
	else swap(obj, objType, inFloor);
	if (objInHands_ != nullptr)
		objInHands_->onPick();
	SDLGame::instance()->getAudioMngr()->playChannel(Resources::AudioId::PickUp, 0);
}

void Transport::drop(bool onFloor)
{
	if (onFloor)
		objInHands_->setCanInteract(true);
	objInHands_->onDrop(onFloor);
	objInHands_ = nullptr;
	objType_ = Resources::PickableType::none;
}

void Transport::swap(Pickable* obj, Resources::PickableType objType, bool inFloor)
{
	if (objType_ != Resources::PickableType::Dish) {
		objInHands_->onDrop(inFloor);
		objInHands_ = nullptr;
		objInHands_ = obj;
		objType_ = objType;

	}
}

void Transport::init()
{
	playerTransform_ = GETCMP1_(Transform);
}

void Transport::update()
{
	if (objInHands_ != nullptr && !(playerTransform_->getVel().getX() == 0 && playerTransform_->getVel().getY() == 0)) {

		float angle = -((atan2(playerTransform_->getVel().getY(), playerTransform_->getVel().getX()) * 180) / M_PI);
		int centerX = playerTransform_->getPos().getX() + playerTransform_->getW() / 2;
		int centerY = playerTransform_->getPos().getY() + playerTransform_->getH() / 2;

		Vector2D objPos = Vector2D();
		double offsetX = playerTransform_->getW() / 2;
		double offsetY = playerTransform_->getH() / 2;

		Vector2D objOffset = objInHands_->getSize() / 2;

		if ((angle > (-22.5) && angle <= 22.5)) { //Derecha
			objPos = Vector2D(centerX + offsetX, centerY);
		}
		else if ((angle > 22.5 && angle <= 67.5)) { //Arriba a la derecha
			objPos = Vector2D(centerX + offsetX, centerY - offsetY);
		}
		else if ((angle > 67.5 && angle <= 112.5)) { //Arriba
			objPos = Vector2D(centerX, centerY - offsetY);
		}
		else if ((angle > 112.5 && angle <= 157.5)) { //Arriba a la izquierda
			objPos = Vector2D(centerX - offsetX, centerY - offsetY);
		}
		else if ((angle > 157.5 || angle <= (-157.5))) { //izquierda
			objPos = Vector2D(centerX - offsetX, centerY);
		}
		else if ((angle > (-157.5) && angle <= (-112.5))) { //Abajo a la izquierda
			objPos = Vector2D(centerX - offsetX, centerY + offsetY);
		}
		else if ((angle > (-112.5) && angle <= (-67.5))) { //Abajo
			objPos = Vector2D(centerX, centerY + offsetY);
		}
		else if ((angle > (-67.5) && angle <= (-22.5))) { //abajo a la derecha
			objPos = Vector2D(centerX + offsetX, centerY + offsetY);
		}

		objInHands_->setPos(objPos - objOffset);
	}
}
