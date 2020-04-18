#pragma once
#include "jute.h"
#include "Resources.h"
#include <array>
#include <vector>

class EntityManager;
class Entity;
class ScreenLoader;
class Interactive;

class LevelInitializer
{
public:
	LevelInitializer(EntityManager* em, Resources::Level level, ScreenLoader* sL);
private:

	void initialize_players();
	void initialize_ingredientsPool();
	void initialize_foodPool();
	void initialize_utensilPool();
	void initialize_cookersPool();
	void initialize_shelfs();
	void initialize_sinks();
	void initialize_bin();
	void initialize_dishes();
	void initialize_gameManager();
	void initialize_foodGivers();
	void initialize_colSystem();
	void initialize_feedback();

	double casilla;

	std::array<Entity*, 2> players;
	Entity* ingPoolEntity_;
	Entity* utensil;
	Entity* foodPool;
	Entity* gameManager;
	std::vector<Interactive*> interactives_;

	ScreenLoader* sL;

	EntityManager* emPlaystate;
	jute::jValue jsonLevel;
	jute::jValue jsonGeneral;
};
