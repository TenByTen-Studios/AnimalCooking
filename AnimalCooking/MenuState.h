#pragma once
#include "State.h"
#include "MenuButtonBehaviour.h"
#include "MenuButtonRenderer.h"
#include "Transform.h"
#include "SDLGame.h"
#include "AnimalCooking.h"
#include "ConfigState.h"
#include "MapState.h"
#include "checkML.h"
#include "CreditsState.h"
#include "Texture.h"
#include "AnimalCooking.h"

class MenuState: public State
{
	enum SelectionState { Options, Play, Credits, Exit};

public:
	MenuState(AnimalCooking* ac);
	~MenuState();

	void leftState();
	void rightState();
	void selectedState();

private:
	SelectionState state;
	SDL_Rect backgroundRect;
	SDL_Rect ruedecillaRect;
	double ruedecillaAngle;

	Texture* background;
	Texture* ruedecilla;
	Texture* ruedecillaShadow;

	Entity* leftButton_;
	Entity* rightButton_;
	Entity* selectionButton_;

	void draw() override;

	void playMenuCallback();
	void optionsMenuCallback();
	void creditsMenuCallback();
	void closeGame();
};

