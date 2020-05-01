#include "Ingredient.h"
#include "SDLGame.h"
#include "SDL_macros.h"

void Ingredient::update() {
	pos_ = pos_ + vel_;
}

void Ingredient::render() const {
	SDL_Rect rect = RECT(pos_.getX(), pos_.getY(), size_.getX(), size_.getY());

	texture_->render(rect); //Cambiar si los ingredientes vienen todos en una misma textura para usar el clip
}

//Si colisiona en horizontal; llamado por game manager
void Ingredient::onCollisionX() {

}

//Si colisiona en vertical; llamado por game manager
void Ingredient::onCollisionY() {
	
}

void Ingredient::destroy(Resources::UtensilType utensilio)
{
	ingredientPool_->deleteIngredient(it_);
}
