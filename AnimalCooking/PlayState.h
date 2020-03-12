#pragma once

#include "State.h"
#include "Entity.h"
#include "SDLGame.h"
#include "Manager.h"


class PlayState : public State
{
public:
	PlayState() : State() {


		
		 
		 
				
	}
	void update() override
	{
	}
	
	void draw() override 
	{
		State::draw();
	}

	//virtual void handleEvent();
private:

	
};

