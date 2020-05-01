#include "OrderServiceViewer.h"

void OrderServiceViewer::init()
{
	textLeft = SDLGame::instance()->getTextureMngr()->getTexture(Resources::TextureId::BarraIzda);
	textMid = SDLGame::instance()->getTextureMngr()->getTexture(Resources::TextureId::BarraCentro);
	textRight = SDLGame::instance()->getTextureMngr()->getTexture(Resources::TextureId::BarraDcha);
	position = RECT(entity->getPos().getX(), entity->getPos().getY(), entity->getSize().getX(), entity->getSize().getY());
}

void OrderServiceViewer::draw()
{
	SDL_Rect dest = position;
	dest.w /= 3;
	textLeft->render(dest);
	dest.x += dest.w;
	textMid->render(dest);
	dest.x += dest.w;
	textRight->render(dest);
}
