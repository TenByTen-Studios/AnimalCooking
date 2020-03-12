#pragma once

#include "State.h"
#include "Food.h"
#include "FoodMotion.h"
#include "FoodViewer.h"
#include "Entity.h"
#include "SDLGame.h"
#include "Manager.h"
#include "DishPool.h":
#include "DishStack.h"
#include "DishViewer.h"

class PlayState : public State
{
public:
	PlayState() : State() {
		Entity* dishes = stage->addEntity();
		 dp=dishes->addComponent<DishPool>();
	     ds = dishes->addComponent<DishStack>(3);
		 dishes->addComponent<DishViewer>();

		
		 
		 
				
	}
	void update() override
	{
		InputHandler* ih = SDLGame::instance()->getInputHandler();
		/*if (ih->isKeyDown(SDLK_UP))
		{
			f->previousFood();
		}
		else if (ih->isKeyDown(SDLK_DOWN))
			f->nextFood();
		else if (ih->isKeyDown(SDLK_a))
			f->addFood(new provisional1());
		else if (ih->isKeyDown(SDLK_s))
			f->addFood(new Provisional2());
		else if (ih->isKeyDown(SDLK_d))
			f->takeFood();
	 */

		if (ih->isKeyDown(SDLK_UP))
		{
			ds->getDish(Vector2D(SDLGame::instance()->getWindowWidth() / 2, SDLGame::instance()->getWindowHeight() / 2));
		}
		else if (ih->isKeyDown(SDLK_DOWN)) {
			ds->removeDish(dp->getDishes().back());
		}
		else if (ih->isKeyDown(SDLK_RIGHT))
			dp->getDishes().back()->addFood(new SlicedTomato(Vector2D(400, 200)));


    }
	
	void draw() override 
	{
		State::draw();
	}

	//virtual void handleEvent();
private:
	DishPool* dp = nullptr;
	DishStack* ds = nullptr;
	
};

