#pragma once
#include "Component.h"
#include "SDLGame.h"
#include "Entity.h"
#include "Interactive.h"
#include "Transport.h"
#include "Vector2D.h"
#include "Dish.h"
#include "Manager.h"
#include "OrderServiceViewer.h"
#include "OrderManager.h"
#include "OrderViewer.h"
#include "AIClient.h"

class OrderService: public Entity, public Interactive
{
private:
	OrderManager* orderMngr;

public:
	OrderService(Vector2D pos, Transport* p1, Transport* p2, EntityManager* mng,ScoreManager* scoremanager);
	virtual void action1(int id);
};
