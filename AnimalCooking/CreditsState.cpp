#include "CreditsState.h"




CreditsState::CreditsState(AnimalCooking* ac):State(ac) {
	cout << "Credits";
	Entity* returnToMenuState = stage->addEntity();
	returnToMenuState->addComponent<Transform>(Vector2D(SDLGame::instance()->getWindowWidth() / 2, SDLGame::instance()->getWindowHeight()/ 4),Vector2D(0,0),100,50,0);
	returnToMenuState->addComponent<ButtonBehaviour>(GoBackMenu, app);
	returnToMenuState->addComponent<ButtonRenderer>(SDLGame::instance()->getTextureMngr()->getTexture(Resources::Button),nullptr);
	//Se pondr�an los 

	//Entity* nombre = stage->addEntity();
	//nombre->addComponent<Transform>(Vector2D(SDLGame::instance()->getWindowWidth()/2, SDLGame::instance()->getWindowHeight()*3/4),Vector2D(0,-10),300,100,0);
	//nombre->addComponent<ButtonRenderer>(SDLGame::instance()->getTextureMngr()->getTexture(Resources::Boton), SDLGame::instance()->getTextureMngr()->getTexture(Resources::Boton));
}


void CreditsState::GoBackMenu(AnimalCooking* ac) {
	SDLGame::instance()->getAudioMngr()->playChannel(Resources::AudioId::Tecla1 + SDLGame::instance()->getRandGen()->nextInt(0, 6), 0);
	SDLGame::instance()->getFSM()->popState();
	

}