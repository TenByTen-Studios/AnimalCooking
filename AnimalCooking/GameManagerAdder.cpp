#include "GameManagerAdder.h"
#include "GameLogic.h"
#include "UtensilsPool.h"
#include "FoodPool.h"
#include "IngredientsPool.h"
#include "Manager.h"

GameManagerAdder::GameManagerAdder(EntityManager* em, jute::jValue& jsonLevel, jute::jValue& jsonGeneral,
	std::array<Entity*, 2>& player, UtensilsPool* utensilpool_, FoodPool* fp, IngredientsPool* ip)
{
	Entity* gameManager = em->addEntity();
	GameLogic* glogic = gameManager->addComponent<GameLogic>();
	gameManager->addComponent<GameControl>(GETCMP2(player[0], Transport), GETCMP2(player[1], Transport), utensilpool_, fp);
	glogic->setUtensilsPool(utensilpool_);
	glogic->setIngredientPool(ip);

	jute::jValue components = jsonLevel["GameManager"]["components"];
	for (int c = 0; c < components.size(); ++c) {
		initializeComponent(components[c].as_string(), gameManager);
	}
}

constexpr unsigned int str2int(const char* str, int h = 0)
{
	return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

//La cadena (component) no puede superar 10 caracteres
void GameManagerAdder::initializeComponent(const string& component, Entity* entity)
{
	switch (str2int(component.c_str()))
	{
	case str2int("AdvEffect"):
		break;
	default:
		break;
	}
}