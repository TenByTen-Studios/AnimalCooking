#include "MenuButtonBehaviour.h"
#include "Entity.h"
#include "MenuState.h"
#include "SDL_macros.h"

void MenuButtonBehaviour::init()
{
	tr_ = GETCMP1_(Transform);
}

void MenuButtonBehaviour::update()
{
	InputHandler* ih = InputHandler::instance();
	Vector2D buttonPos = tr_->getPos();
	Vector2D mousePos = ih->getMousePos();

	SDL_Point mousePosition = { mousePos.getX(), mousePos.getY() };
	SDL_Rect buttonRect = RECT(buttonPos.getX(), buttonPos.getY(), tr_->getW(), tr_->getH());

	if (SDL_PointInRect(&mousePosition, &buttonRect) && ih->getMouseButtonState(InputHandler::MOUSEBUTTON::LEFT)) {
		right_ ? menuState_->rightState(): menuState_->leftState();
	}
}
