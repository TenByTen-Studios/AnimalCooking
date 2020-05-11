#pragma once
#include "PlayerViewer.h"
#include "GameConfig.h"

void PlayerViewer::init()
{	
	tr_ = GETCMP1_(Transform);
	animator = GETCMP1_(Animator);
	tp = p->getComponent<Transport>(ecs::Transport);
}

void PlayerViewer::update()
{
	if ((tp->getObjectTypeInHands() == Resources::PickableType::Dish || tp->getObjectTypeInHands() == Resources::PickableType::Food) && animator->getDir().getY() > 0)
	{
		//std::swap(em->getGroups()[ecs::GroupID::PlayerLayer1].at(0), em->getGroups()[ecs::GroupID::PlayerLayer1].at(1));
		if (em->getGroups()[ecs::GroupID::PlayerLayer1].size() > 0) 
		{			
			em->getGroups()[ecs::GroupID::PlayerLayer1].remove(p);
			em->getGroups()[ecs::GroupID::PlayerLayerAux1].push_back(p);
		}
	}
	else if ((tp->getObjectTypeInHands() == Resources::PickableType::Dish || tp->getObjectTypeInHands() == Resources::PickableType::Food) && animator->getDir().getY() < 0)
	{
		if (em->getGroups()[ecs::GroupID::PlayerLayerAux1].size() > 0) 
		{
			em->getGroups()[ecs::GroupID::PlayerLayerAux1].remove(p);
			em->getGroups()[ecs::GroupID::PlayerLayer1].push_back(p);
		}
	}
}


void PlayerViewer::setIdle(SDL_Rect dest,int fil1,int fil2)
{	
	if ((animator->getDir().getX() > 0 && animator->getDir().getY() == 0) || (animator->getDir().getY() > 0 && animator->getDir().getX() > 0) || ((animator->getDir().getY() > 0 && animator->getDir().getX() == 0)) || (animator->getDir().getX() == 0 && animator->getDir().getY() == 0)) idleSpritesheet_->renderFrame(dest, fil1, int(((game_->getTime() / config::ANIM_SPEED) % idleSpritesheet_->getNumCols())), 0);
	else if ((animator->getDir().getX() < 0 && animator->getDir().getY() == 0) || (animator->getDir().getY() > 0 && animator->getDir().getX() < 0))  idleSpritesheet_->renderFrame(dest, fil1, int(((game_->getTime() / config::ANIM_SPEED) % idleSpritesheet_->getNumCols())), 0, SDL_FLIP_HORIZONTAL);
	else if ((animator->getDir().getY() < 0 && animator->getDir().getX() == 0) || (animator->getDir().getY() < 0 && animator->getDir().getX() > 0)) idleSpritesheet_->renderFrame(dest, fil2, int(((game_->getTime() / config::ANIM_SPEED) % idleSpritesheet_->getNumCols())), 0);
	else if (animator->getDir().getY() < 0 && animator->getDir().getX() < 0)   idleSpritesheet_->renderFrame(dest, fil2, int(((game_->getTime() / config::ANIM_SPEED) % idleSpritesheet_->getNumCols())), 0, SDL_FLIP_HORIZONTAL);
}

void PlayerViewer::setWalkOrAttack(SDL_Rect dest, Texture* spriteSheet,int fil1, int fil2)
{
	if ((animator->getDir().getX() > 0 && animator->getDir().getY() == 0) || (animator->getDir().getY() > 0 && animator->getDir().getX() == 0) || (animator->getDir().getY() > 0 && animator->getDir().getX() > 0)) spriteSheet->renderFrame(dest, fil1, int(((game_->getTime() / config::ANIM_SPEED) % spriteSheet->getNumCols())), 0); 
	else if ((animator->getDir().getX() < 0 && animator->getDir().getY() == 0) || animator->getDir().getY() > 0 && animator->getDir().getX() < 0) spriteSheet->renderFrame(dest, fil1, int(((game_->getTime() / config::ANIM_SPEED) % spriteSheet->getNumCols())), 0, SDL_FLIP_HORIZONTAL);
	else if ((animator->getDir().getY() < 0 && animator->getDir().getX() == 0) || (animator->getDir().getY() < 0 && animator->getDir().getX() > 0)) spriteSheet->renderFrame(dest, fil2, int(((game_->getTime() / config::ANIM_SPEED) % spriteSheet->getNumCols())), 0);
	else if (animator->getDir().getY() < 0 && animator->getDir().getX() < 0) spriteSheet->renderFrame(dest, fil2, int(((game_->getTime() / config::ANIM_SPEED) % spriteSheet->getNumCols())), 0, SDL_FLIP_HORIZONTAL);
}

void PlayerViewer::draw()
{
	SDL_Rect dest = {tr_->getPos().getX(),tr_->getPos().getY(),tr_->getW(),tr_->getH()};

		
	switch (animator->getCurrentState())
	{
	case Animator::States::Idle:
		setIdle(dest, 0, 1);
		break;
	case Animator::States::IdleWithKnife:
		setIdle(dest, 2, 3);
		break;
	case Animator::States::IdleWithMace:
		setIdle(dest, 4, 5);
		break;
	case Animator::States::IdleWithNet:
		setIdle(dest,8,9);
		break;
	case Animator::States::IdleWithGrater:
		setIdle(dest, 11, 12);
		break;
	case Animator::States::IdleWithDishFood:
		setIdle(dest, 6, 7);
		break;

	case Animator::States::Walk:
		setWalkOrAttack(dest, walkSpritesheet_,0, 1);		
		break;
	case Animator::States::WalkWithKnife:
		setWalkOrAttack(dest, walkSpritesheet_,2,3);
		break;
	case Animator::States::WalkWithMace:
		setWalkOrAttack(dest, walkSpritesheet_, 4, 5);
		break;
	case Animator::States::WalkWithNet:
		setWalkOrAttack(dest, walkSpritesheet_, 8, 9);
		break;
	case Animator::States::WalkWithGrater:
		setWalkOrAttack(dest, walkSpritesheet_,11,12);
		break;
	case Animator::States::WalkWithDishFood:
		setWalkOrAttack(dest, walkSpritesheet_, 6, 7);
		break;

	case Animator::States::AttackWithKnife:
		setWalkOrAttack(dest,attackSpritesheet_ ,0, 1);
		break;
	case Animator::States::AttackWithMace:
		setWalkOrAttack(dest, attackSpritesheet_, 2, 3);
		break;
	case Animator::States::AttackWithNet:
		setWalkOrAttack(dest, attackSpritesheet_, 4, 5);
		break;
	case Animator::States::AttackWithGrater:
		setWalkOrAttack(dest, attackSpritesheet_, 7, 8);
		break;

	default:
		break;
	}	
}
