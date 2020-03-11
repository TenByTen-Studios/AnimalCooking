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

		 Dish* d1 = ds->getDish(Vector2D(100, 100));

		 SlicedTomato* tomato = new SlicedTomato(d1->getPos() + Vector2D(d1->getWidth() / 4, d1->getHeight() / 4));
		 tomato->setSize(Vector2D(tomato->getSize() * 0.35));
		 d1->addFood(tomato);

		 SlicedTomato* tomato2 = new SlicedTomato(d1->getPos() + Vector2D(d1->getWidth() / 3, d1->getHeight() / 3));
		 tomato2->setSize(Vector2D(tomato2->getSize() * 0.35));
		 d1->addFood(tomato2);

		 SlicedTomato* tomato3 = new SlicedTomato(d1->getPos() + Vector2D(d1->getWidth() / 2, d1->getHeight() / 2));
		 tomato3->setSize(Vector2D(tomato3->getSize() * 0.35));
		 d1->addFood(tomato3);

		 SlicedTomato* tomato4 = new SlicedTomato(d1->getPos() + Vector2D(d1->getWidth() / 2.5, d1->getHeight() / 2.5));
		 tomato4->setSize(Vector2D(tomato4->getSize() * 0.35));
		 d1->addFood(tomato4);

		 Dish* d2 = ds->getDish(Vector2D(220, 100));
		 SlicedTomato* tomato5 = new SlicedTomato(d2->getPos() + Vector2D(d2->getWidth() / 4, d2->getHeight() / 2.5));
		 tomato5->setSize(Vector2D(tomato5->getSize() * 0.35));
		 d2->addFood(tomato5);
		 

		 Dish* d3 = ds->getDish(Vector2D(320, 100));
		 
		 
		 
				
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

		/*if (ih->isKeyDown(SDLK_UP))
		{
			ds->getDish();
		}
		else if (ih->isKeyDown(SDLK_DOWN)) {
			ds->removeDish();
		}*/


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

