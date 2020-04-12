#pragma once
#include "Adversity.h"
#include "SDL_macros.h"
#include "Texture.h"
#include "AdversityManager.h"

class PlaneAdversity : public Adversity
{
	Texture* planeTexture_;
	SDL_Rect planeRect_;
	int velocity_;
	float force_;

	void StartPlane();

public:
	PlaneAdversity(AdversityManager* am) : Adversity(am) { StartPlane(); }
	~PlaneAdversity() {}
	
	void update();
	void draw();
	void reset();
};

