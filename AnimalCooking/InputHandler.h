#pragma once

#include <SDL.h>
#include <array>
#include "Vector2D.h"
#include <memory>

using namespace std;

class InputHandler {
public:
	enum MOUSEBUTTON : Uint8 {
		LEFT = 0, MIDDLE = 1, RIGHT = 2
	};

	InputHandler(InputHandler&) = delete;
	InputHandler& operator=(InputHandler&) = delete;

	virtual ~InputHandler();

	static InputHandler* instance() {
		if (instance_.get() == nullptr) {
			instance_.reset(new InputHandler());
		}
		return instance_.get();
	}
	// keyboard
	inline bool keyDownEvent() {
		return isKeyDownEvent_;
	}
	inline bool keyUpEvent() {
		return isKeyUpEvent_;
	}
	inline bool isKeyDown(SDL_Scancode key) {
		// return kbState_[key] == 1;
		return keyDownEvent() && kbState_[key] == 1;
	}
	inline bool isKeyDown(SDL_Keycode key) {
		return isKeyDown(SDL_GetScancodeFromKey(key));
	}
	inline bool isKeyUp(SDL_Scancode key) {
		// kbState_[key] == 0;
		return keyUpEvent() && kbState_[key] == 0;
	}
	inline bool isKeyUp(SDL_Keycode key) {
		return isKeyUp(SDL_GetScancodeFromKey(key));
	}
	// mouse
	inline bool mouseMotionEvent() {
		return isMouseMotionEvent_;
	}
	inline bool mouseButtonEvent() {
		return isMouseButtonEvent_;
	}
	inline bool mouseButtonUpEvent() {
		return isMouseButtonUpEvent_;
	}
	inline const Vector2D& getMousePos() {
		return mousePos_;
	}
	inline int getMouseButtonState(MOUSEBUTTON b) {
		return mbState_[b];
	}
	inline const SDL_Keycode& getLastKeyPressed() const { return lastKeyPressed_; }



	// Joystick
	// see:
	//   Chapter 4 of 'SDL Game Development' book
	//   Available online via https://biblioteca.ucm.es/
	//

	// update the state
	void update(SDL_Event& event);
	void clearState();
private:
	InputHandler();

	inline void onKeyDown(SDL_Event& event) {
		isKeyDownEvent_ = true;
		// kbState_ = SDL_GetKeyboardState(0);
		lastKeyPressed_ = event.key.keysym.sym;
	}
	inline void onKeyUp(SDL_Event& event) {
		isKeyUpEvent_ = true;
		// kbState_ = SDL_GetKeyboardState(0);
	}
	inline void onMouseMotion(SDL_Event& event) {
		isMouseMotionEvent_ = true;
		mousePos_.set(event.motion.x, event.motion.y);
	}
	inline void onMouseButtonChange(SDL_Event& event, bool isDown) {
		isMouseButtonEvent_ = true;
		if (event.button.button == SDL_BUTTON_LEFT) {
			mbState_[LEFT] = isDown;
		}
		else if (event.button.button == SDL_BUTTON_MIDDLE) {
			mbState_[MIDDLE] = isDown;
		}
		else if (event.button.button == SDL_BUTTON_RIGHT) {
			mbState_[RIGHT] = isDown;
		}

		if (event.type == SDL_MOUSEBUTTONUP) {
			isMouseButtonUpEvent_ = true;
			if (event.button.button == SDL_BUTTON_LEFT) {
				mbState_[LEFT] = false;
			}
			else if (event.button.button == SDL_BUTTON_MIDDLE) {
				mbState_[MIDDLE] = false;
			}
			else if (event.button.button == SDL_BUTTON_RIGHT) {
				mbState_[RIGHT] = false;
			}
		}
	}

	static unique_ptr<InputHandler> instance_;
	const Uint8* kbState_;
	Vector2D mousePos_;
	std::array<bool, 3> mbState_;
	SDL_Keycode lastKeyPressed_;

	bool isKeyUpEvent_;
	bool isKeyDownEvent_;
	bool isMouseMotionEvent_;
	bool isMouseButtonEvent_;
	bool isMouseButtonUpEvent_;


};

