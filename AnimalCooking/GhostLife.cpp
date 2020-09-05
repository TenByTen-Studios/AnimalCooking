#include "GhostLife.h"
#include "Entity.h"
#include "Ghost.h"

GhostLife::GhostLife(): Component(ecs::GhostLife), tr(nullptr), 
	startOfLife(), 
	lenghtOfLife(2500) //2.5 seconds
{
}

void GhostLife::init()
{
	tr = GETCMP1_(Transform);
	startOfLife = game_->getTime();
}

void GhostLife::update()
{
	if (game_->getTime() > startOfLife + lenghtOfLife) {
		static_cast<Ghost*>(entity_)->deActivate();
	}
	tr->setPosY(tr->getPos().getY() - 1);
}

void GhostLife::restart()
{
	startOfLife = game_->getTime();
}
