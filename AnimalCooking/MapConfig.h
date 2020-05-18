#pragma once
#include "Vector2D.h"
#include "SDL_rect.h"
#include <vector>

struct levelInfo {
	string name = "";
	unsigned int stars = 0;
	string lore = "";
	SDL_Rect houseBox = SDL_Rect();
	Vector2D housePosition = Vector2D();
	Vector2D buttonPosition = Vector2D();
	bool unlocked = false;
};

class MapConfig {
public: 
	MapConfig();
	~MapConfig() {};

	const vector <levelInfo>& getLevelInfoRecipes() { return levelsRecipes; }

private:
	void fill();
	vector <levelInfo> levelsRecipes;
};