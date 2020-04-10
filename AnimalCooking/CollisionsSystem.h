#pragma once
#include "Component.h"
#include <list>

class Ingredient;
class Interactive;
class Transform;
class CollisionsSystem :
	public Component
{
public:
	CollisionsSystem() :Component(ecs::CollisionsSystem) { }

	void addCollider(Transform* t, bool isInmovable = true) { entidadesTr.push_back(std::make_pair(t, isInmovable)); }
	void addCollider(Interactive* i) { entidadesInt.push_back(std::make_pair(i, false)); }
	void addCollider(Ingredient* i, bool isInmovable = true) { entidadesIng.push_back(std::make_pair(i, isInmovable)); }
	void update();

private:
	list<std::pair<Transform*, bool>> entidadesTr;
	list<std::pair<Interactive*, bool>> entidadesInt;
	list<std::pair<Ingredient*, bool>> entidadesIng;

	list<SDL_Rect> collisions(SDL_Rect body);

	void checkCollision(SDL_Rect body, SDL_Rect other, list<SDL_Rect>& collisions);
	void resolveCollisions(Vector2D& pos, const Vector2D& size, const Vector2D& vel);

	void singleCollision(Vector2D& pos, const Vector2D& size, const Vector2D& vel, const SDL_Rect& col);
	void verticalCollision(Vector2D& pos, const Vector2D& size, const Vector2D& vel, const SDL_Rect& col);
	void horizontalCollision(Vector2D& pos, const Vector2D& size, const Vector2D& vel, const SDL_Rect& col);
};

