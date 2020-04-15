#pragma once
#include "Component.h"

class Animator : public Component	
{
	
public:

	enum States {Idle, Walk, Attack};
	
	Animator();
	~Animator() { }

	States getCurrentState() { return currentState; };
	void setCurrentState(States s) { currentState = s; };

	SDL_Rect& animate(Texture* t, int fx, int fy,int numRows=1, int numCols=1);

	int getAnimSpeed() { return animSpeed; }
	void setAnimSpeed(int s) { animSpeed = s; }

private:

	States currentState;
	SDL_Rect clip;
	int animSpeed = 60;
};
