#pragma once
#include "SDL.h"

namespace config {
	//AI CLIENT
	//constexpr int AI_CLIENT_DELTA_TIME_PER_ORDER = 25;
	constexpr int AI_CLIENT_SECONDS_PER_ING = 5;

	//AI INGREDIENT
	constexpr int AI_INGREDIENT_RANGE = 250;

	constexpr int AI_INGREDIENT_MIN_TIME_WALKING = 500;
	constexpr int AI_INGREDIENT_MIN_TIME_IDLE = 500;
	constexpr int AI_INGREDIENT_MAX_TIME_IDLE = 2000;

	constexpr int AI_INGREDIENT_MAX_VEL = 2;

	//ANIMATOR
	constexpr int ANIM_SPEED = 60;

	//COOKERS
	constexpr int SKILLET_SECONDS_TO_COOK = 10;
	constexpr int OVEN_SECONDS_TO_COOK = 15;

	//DISHES
	constexpr int DISH_MAX_INGR = 5;

	//INGREDIENTS
	constexpr int ING_STARTING_DELTA_TIME = 0.5;
	constexpr int ING_MAX_IN_SCENE = 8;

	//PauseState
	constexpr double PAUSESTATE_BUTTON_WIDTH = 1 / 10; //Porcentaje respecto a la pantalla
	constexpr double PAUSESTATE_BUTTON_HEIGHT = 1 / 15; //Porcentaje respecto a la pantalla

	//Player
	constexpr double PLAYER_SPEED = 5.3;
	constexpr double INTERACTION_RECT_OFFSET = 1;
	constexpr double INTERACTION_RECT_SIDELENGTH = 1;

	//Score Viewer
	constexpr double SCOREVIEWER_BUTTON_WIDTH = 1 / 10; //Porcentaje respecto a la pantalla
	constexpr double SCOREVIEWER_BUTTON_HEIGHT = 1 / 15; //Porcentaje respecto a la pantalla

	struct Options
	{
		//PlayerController 1
		SDL_Keycode PLAYERCONTROLLER_KEYBOARD_PLAYER1_KEYCODE_UP = SDLK_w;
		SDL_Keycode PLAYERCONTROLLER_KEYBOARD_PLAYER1_KEYCODE_DOWN = SDLK_s;
		SDL_Keycode PLAYERCONTROLLER_KEYBOARD_PLAYER1_KEYCODE_LEFT = SDLK_a;
		SDL_Keycode PLAYERCONTROLLER_KEYBOARD_PLAYER1_KEYCODE_RIGHT = SDLK_d;
		SDL_Keycode PLAYERCONTROLLER_KEYBOARD_PLAYER1_KEYCODE_PICKUP = SDLK_k;
		SDL_Keycode PLAYERCONTROLLER_KEYBOARD_PLAYER1_KEYCODE_ATTACK = SDLK_p;
		SDL_Keycode PLAYERCONTROLLER_KEYBOARD_PLAYER1_KEYCODE_OPEN = SDLK_f;
		SDL_Keycode PLAYERCONTROLLER_KEYBOARD_PLAYER1_KEYCODE_PREVIOUS = SDLK_q;
		SDL_Keycode PLAYERCONTROLLER_KEYBOARD_PLAYER1_KEYCODE_NEXT = SDLK_e;
		SDL_Keycode PLAYERCONTROLLER_KEYBOARD_PLAYER1_KEYCODE_FINISHER = SDLK_r;

		//PlayerController 2
		SDL_Keycode PLAYERCONTROLLER_KEYBOARD_PLAYER2_KEYCODE_UP = SDLK_UP;
		SDL_Keycode PLAYERCONTROLLER_KEYBOARD_PLAYER2_KEYCODE_DOWN = SDLK_DOWN;
		SDL_Keycode PLAYERCONTROLLER_KEYBOARD_PLAYER2_KEYCODE_LEFT = SDLK_LEFT;
		SDL_Keycode PLAYERCONTROLLER_KEYBOARD_PLAYER2_KEYCODE_RIGHT = SDLK_RIGHT;
		SDL_Keycode PLAYERCONTROLLER_KEYBOARD_PLAYER2_KEYCODE_PICKUP = SDLK_b;
		SDL_Keycode PLAYERCONTROLLER_KEYBOARD_PLAYER2_KEYCODE_ATTACK = SDLK_n;
		SDL_Keycode PLAYERCONTROLLER_KEYBOARD_PLAYER2_KEYCODE_ACTION_3 = SDLK_m;
		SDL_Keycode PLAYERCONTROLLER_KEYBOARD_PLAYER2_KEYCODE_ACTION_4 = SDLK_h;
		SDL_Keycode PLAYERCONTROLLER_KEYBOARD_PLAYER2_KEYCODE_FINISHER = SDLK_j;
	};
}

