#include "WallAdder.h"
#include "Wall.h"
#include "CollisionsSystem.h"
#include "Manager.h"
#include "Transform.h"
#include "Door.h"
#include "SDLRenderer.h"

#define CASTID(t) static_cast<ecs::GroupID>(t - 1)


WallAdder::WallAdder(EntityManager* mngr,  jute::jValue& nivel, jute::jValue& general, CollisionsSystem* colSys_, std::array<Entity*, 2>& players, const double casilla, const double offset)
{
	vector<Data> data; 
	data.push_back(Data(Vector2D(), //Izq Arr hor
		Vector2D(6 * casilla + offset, offset),		
		Resources::TextureId::Suelo));  

	data.push_back(Data(Vector2D(0, offset), //Izq Arr ver
		Vector2D(offset, 7 * casilla),
		Resources::TextureId::Suelo));

	data.push_back(Data(Vector2D(6 * casilla + offset, 0), //medio 1 ver
		Vector2D(offset, 3.75 * casilla + offset),
		Resources::TextureId::Suelo));

	data.push_back(Data(Vector2D(6 * casilla + offset, 5.25 * casilla + offset),	//Medio 2 ver
		Vector2D(offset, 1.75 * casilla),
		Resources::TextureId::Suelo));

	data.push_back(Data(Vector2D(6 * casilla + 2 * offset, 7 * casilla), //Aba hor
		Vector2D(SDLGame::instance()->getWindowWidth() - (6 * casilla + offset) - offset , offset),
		Resources::TextureId::Button));

	data.push_back(Data(Vector2D(6 * casilla + 2 * offset, 0), //Arr hor
		Vector2D(SDLGame::instance()->getWindowWidth() - (6 * casilla + offset) - offset, offset),
		Resources::TextureId::Button));

	data.push_back(Data(Vector2D(SDLGame::instance()->getWindowWidth() - offset, offset), //Der arr ver
		Vector2D(offset, 1 * casilla),
		Resources::TextureId::Button));

	data.push_back(Data(Vector2D(SDLGame::instance()->getWindowWidth() - offset, 2 * casilla + offset), //Der medio 1 ver
		Vector2D(offset, 1 * casilla),
		Resources::TextureId::Button));

	data.push_back(Data(Vector2D(SDLGame::instance()->getWindowWidth() - offset, 4 * casilla + offset), //Der medio 2 ver
		Vector2D(offset, 1 * casilla),
		Resources::TextureId::Button));

	data.push_back(Data(Vector2D(SDLGame::instance()->getWindowWidth() - offset, 6 * casilla + offset), //Der medio 2 ver
		Vector2D(offset, 1 * casilla ),
		Resources::TextureId::Button));

	for (auto& d : data) {
		maker(d, casilla, colSys_, mngr);
	}

	for (int i = 0; i < nivel["Shelfs"]["corners"].size(); ++i) {
		Entity* corner = mngr->addEntity();
		int t = Resources::TextureId::EsquinaSupDchaCopas + (2 * SDLGame::instance()->getRandGen()->nextInt(0, 4));
		if (nivel["Shelfs"]["corners"][i]["sitio"].as_string() == "izq") ++t;
		corner->addComponent<Transform>(Vector2D(nivel["Shelfs"]["corners"][i]["pos"]["x"].as_double() * casilla + offset,
			nivel["Shelfs"]["corners"][i]["pos"]["y"].as_double() * casilla + offset), Vector2D(),
			general["Shelf"]["size"]["width"].as_double() * casilla, general["Shelf"]["size"]["height"].as_double() * casilla);
		corner->addComponent<SDLRenderer>(SDLGame::instance()->getTextureMngr()->getTexture(t), casilla);
		mngr->addToGroup(corner, CASTID(general["Shelf"]["Layer"].as_int()));
		colSys_->addCollider(GETCMP2(corner, Transform), false);
	}

	//Hacer puerta
	Door* d = new Door(Vector2D(5.5 * casilla + offset, 3.75 * casilla + offset), Vector2D(1 * casilla + offset, 1.5 * casilla), 
		SDLGame::instance()->getTextureMngr()->getTexture(Resources::TextureId::Panel), GETCMP2(players[0], Transform), GETCMP2(players[1], Transform), mngr);
	mngr->addEntity(d);
	mngr->addToGroup(d, ecs::GroupID::FoodLayer);
}

void WallAdder::maker(const Data& d, const double casilla, CollisionsSystem* colSys_, EntityManager* mngr)
{
	Wall* w = new Wall(d.pos, d.size, SDLGame::instance()->getTextureMngr()->getTexture(d.t), casilla, mngr);

	mngr->addEntity(w);
	mngr->addToGroup(w, ecs::GroupID::FoodLayer);
	colSys_->addCollider(GETCMP2(w, Transform), false);
}
