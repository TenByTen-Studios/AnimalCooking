#include "DishStackViewer.h"
#include"Entity.h"
#include "SDL_macros.h"

DishStackViewer ::DishStackViewer() : Component(ecs::DishStackViewer)
{

}

void DishStackViewer::init()
{
	trDishStack = GETCMP1_(Transform);
	stack = game_->getTextureMngr()->getTexture(Resources::Repisa);
}

void DishStackViewer::draw()
{	
	stack->render(RECT(trDishStack->getPos().getX(), trDishStack->getPos().getY(), trDishStack->getW(), trDishStack->getH()));
}