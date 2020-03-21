#pragma once
#include "Component.h"
#include "Interactive.h"
#include "Transport.h"
#include "Pickable.h"
#include "ShelfViewer.h"
#include "Entity.h"
#include "SDLGame.h"
#include "ShelfViewer.h"
#include "Utensil.h"
#include "Dish.h"
#include "Manager.h"
class Shelf :
	public Entity, public Interactive
{

private:
	Pickable* content;
	Resources::PickableType contentType;
public:
	Shelf(Pickable* c,Transport* p1, Transport* p2, EntityManager* mng);
	void Swap(Transport* player, Resources::PickableType onPlayerHands);
	virtual void action1(int id);
	Pickable* getContent() { return content; }
};
