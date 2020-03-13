#pragma once

#include "State.h"
#include "Entity.h"
#include "SDLGame.h"
#include "Manager.h"

#include "DishPool.h":
#include "DishStack.h"
#include "DishViewer.h"
#include "Food.h"


class PlayState : public State
{
public:
	PlayState() : State() {

		Entity* dishes = stage->addEntity();
		dp = dishes->addComponent<DishPool>();
		ds = dishes->addComponent<DishStack>(6);
		dishes->addComponent<DishViewer>();

		d1 = ds->getDish(Vector2D(100,100));
		d2 = ds->getDish(Vector2D(200,100));
		d3 = ds->getDish(Vector2D(300,100));

		d1->addFood(new SlicedTomato(Vector2D()));
		d1->addFood(new SlicedTomato(Vector2D()));
		d1->addFood(new SlicedTomato(Vector2D()));
		d1->takeFood();
		d3->addFood(new SlicedTomato(Vector2D()));

		/*ds->removeDish(d2);
		ds->removeDish(d3);
		ds->removeDish(d1);*/
				
	}
	void update() override
	{

		

		/*
		InputHandler* ih = SDLGame::instance()->getInputHandler();
		if (ih->isKeyDown(SDLK_UP))
		{
			d1->previousFood();
		}
		else if (ih->isKeyDown(SDLK_DOWN))
			d1->nextFood();
		else if (ih->isKeyDown(SDLK_a))
			d1->addFood(new SlicedTomato(Vector2D()));
		else if (ih->isKeyDown(SDLK_s))
			d1->addFood(new SlicedTomato(Vector2D()));
		else if (ih->isKeyDown(SDLK_d))
			d1->takeFood();
	 */
	}
	
	void draw() override 
	{
		State::draw();
	}

	//virtual void handleEvent();
private:
	DishPool* dp = nullptr;
	DishStack* ds = nullptr;
	
	Dish* d1 = nullptr;
	Dish* d2 = nullptr;
	Dish* d3 = nullptr;

};

