#pragma once
#include <ctime>

namespace ecs {

using CmpIdType = std::size_t;

enum CmpId : CmpIdType {
	Transform = 0,

	GPadController, //Controls
	KeyBoardController,
	IngredientMotion,

	AIIngredient, //AI

	GameControl, //Game
	GameLoader,
	GameLogic,
	GameSave,

	Attack, //Player
	PlayerController,
	PlayerViewer,
	PlayerMotion,
	Transport,
	Selector,
	InteractionRect,

	DishPool,		//Dish
	DishMotion,
	DishViewer,
	DishStack,
	InOutFood,		//ELIMINAR SI NO SE IMPLEMENTA
	DishFinisher,

	FoodMotion,		//Food
	FoodViewer,
	FoodPool,


	IngredientsPool, //Pools
	UtensilsPool,
	UtensilsViewer,
	UtensilsMotion,


	CookerPool,		//Cookers
	CookerViewer,	
	FoodCooker,
	InsertExpel,

	SDLRenderer, //Renderer
	SDLRendererFrame,
	StaticRenderer,
	IngredientViewer,
	BinViewer,

	GameManager, //Utils
	ScoreManager,
	ScoreViewer,
	SoundManager,
	SelectorPopUp,
	SelectorPopUpEntity,

	ButtonBehaviour, //Buttons
	ButtonRenderer,
	ButtonsViewer,
	ButtonDirector,

	LoadingBarViewer, //Bar

	//
	// don't touch the rest of this enum, it is to identify the max
	// number of components
	_LastCmptId_
};

constexpr std::size_t maxComponents = _LastCmptId_;

// these two should be used to get a component via the field
// entity_
#define GETCMP2_(id,type)  GETCMP3(entity_,id,type)
#define GETCMP1_(type)     GETCMP3(entity_,ecs::type,type)

// these two should be used to get a component via an
// entity e provided as a parameter
#define GETCMP2(e,type) GETCMP3(e,ecs::type,type)
#define GETCMP3(e,id,type) e->getComponent<type>(id)

}

