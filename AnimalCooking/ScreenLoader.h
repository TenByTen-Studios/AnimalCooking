#pragma once
#include "State.h"
#include "FSM.h"
#include "PlayState.h"

class ScreenLoader : public State
{
public:
	ScreenLoader(int nivel, AnimalCooking* ac);
	~ScreenLoader() { }
	void resetResources(); // Resources::Nivel nivel: es un enum que indica que recursos cargar en memoria
	void updateLength();

	EntityManager* getEntityManager() { return emPlaystate; }
	const int getLevel() const { return level; }

private:
	static void goToPlayState(AnimalCooking* ac);

	void initialize();
	void loadTextures(SDL_Renderer* renderer_);
	void loadSpriteSheets(SDL_Renderer* renderer_);
	void loadFonts();
	void loadMessagges(SDL_Renderer* renderer_);
	void loadSounds();
	void loadMusics();

	Entity* loadingBar_;
	Entity* buttonGo_;
	Entity* padNavigation_;
	EntityManager* emPlaystate;

	int level;
};
