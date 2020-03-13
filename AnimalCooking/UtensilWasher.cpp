#include "UtensilWasher.h"
UtensilWasher::UtensilWasher(SDL_Keycode button1, SDL_Keycode button2, SDL_Keycode button3, SDL_Keycode button4) :

	Component(ecs::UtensilWasher), toBeWashedUtensil(nullptr) {
	keys.push_back(button1);
	keys.push_back(button2);
	keys.push_back(button3);
	keys.push_back(button4);
	keys.push_back(SDL_CONTROLLER_BUTTON_A);
	keys.push_back(SDL_CONTROLLER_BUTTON_B);
	keys.push_back(SDL_CONTROLLER_BUTTON_X);
	keys.push_back(SDL_CONTROLLER_BUTTON_Y);
	lastClean = 0;
	rateOfFire = 0;


}
void UtensilWasher::update() {
	//si hay que limpiar generamos un n�mero en el intervalo [0,4] que representar� el bot�n a pulsar.
	//como en el vector est�n primero las teclas y luego los botones correspondientes del mando,
	//cada tecla est� separada 4 posiciones de su bot�n correspondiente, as� que para limpiar el 
	//utensilio basta con comprobar que se est� pulsando la tecla o el bot�n
	if (toBeWashedUtensil != nullptr) {
		int rndm = SDLGame::instance()->getRandGen()->nextInt(0, 5);
		InputHandler* ih = SDLGame::instance()->getInputHandler();
		GPadController* gpad = GPadController::instance();
		//aqu� habr�a que preguntar al playerController su ID, pero de momento no se me ocurre c�mo
		if (ih->isKeyUp(keys.at(rndm) || gpad->getButtonState(0, keys.at((int8_t)rndm + 4))))
		{
			toBeWashedUtensil->cleanUp();
			if (toBeWashedUtensil->getDirt() <= 0)
				toBeWashedUtensil = nullptr;
		}
	}
}