#include "MapState.h"
#include "ScreenLoader.h"
#include "FSM.h"
#include "ButtonRenderer.h"
#include "ButtonBehaviour.h"

 void MapState::screenLoaderCallback() {
	SDLGame::instance()->getFSM()->pushState(new ScreenLoader(Resources::Level::Nivel1));
}
void MapState::backButtonCallback() {
	SDLGame::instance()->getFSM()->popState();
}
MapState::MapState(): State() {
	game_ = SDLGame::instance();
	cout << "Map State" << endl;

	Entity* screenLoaderButton_ = stage->addEntity();
	Entity* backButton_ = stage->addEntity();
	stage->addToGroup(screenLoaderButton_, ecs::GroupID::Layer1);
	stage->addToGroup(backButton_, ecs::GroupID::Layer1);

	screenLoaderButton_->addComponent<Transform>(Vector2D(game_->getWindowWidth() / 2, (game_->getWindowHeight() / 3) * 0), Vector2D(0, 0), 200.0, 100, 0);
	screenLoaderButton_->addComponent<ButtonRenderer>(game_->getTextureMngr()->getTexture(Resources::Button), nullptr);
	screenLoaderButton_->addComponent<ButtonBehaviour>(screenLoaderCallback);

	backButton_->addComponent<Transform>(Vector2D(game_->getWindowWidth() / 2, (game_->getWindowHeight() / 3) * 1), Vector2D(0, 0), 200.0, 100, 0);
	backButton_->addComponent<ButtonRenderer>(game_->getTextureMngr()->getTexture(Resources::Button), nullptr);
	backButton_->addComponent<ButtonBehaviour>(backButtonCallback);
}