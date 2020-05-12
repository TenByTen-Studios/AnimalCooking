#include "HookAdversity.h"
#include "AdversityManager.h"
#include "MultipleAdversityManager.h"

HookAdversity::HookAdversity(AdversityManager* am, MultipleAdversityManager* mam) : Adversity(am, mam)
{
	speed = 5;
	if (adversityMngr_ != nullptr) {
		tP1 = adversityMngr_->getTransformPlayer(Resources::Player::Player1);
		tP2 = adversityMngr_->getTransformPlayer(Resources::Player::Player2);
	}
	else {
		tP1 = multipleAdversityMngr_->getTransformPlayer(Resources::Player::Player1);
		tP2 = multipleAdversityMngr_->getTransformPlayer(Resources::Player::Player2);
	}
	hookTexture = SDLGame::instance()->getTextureMngr()->getTexture(Resources::Cuchillo);
	clipArea.x = 0;
	clipArea.y = 0;
	clipArea.w = 128;
	clipArea.h = 128;
	//clipArea.w /= 5;

	drawingAreaHook1.x = 0;
	drawingAreaHook1.y = 0;
	drawingAreaHook1.w = 128;
	drawingAreaHook1.h = 128;
	drawingAreaHook2.x = 0;
	drawingAreaHook2.y = 0;
	drawingAreaHook2.w = 128;
	drawingAreaHook2.h = 128;

	catched = false;
	changedPositions = false;
	droped = false;
	playersVisible = true;

	hook1Vel = tP1->getPos().getY() / 2000;
	hook2Vel = tP2->getPos().getY() / 2000;
	lastTick = 0;
	lastFrame = 0;
	frameTime = 50;
	animationFrame = 0;

}

void HookAdversity::Start() {
	//Me quedo con las dimensiones de los players y posiciono los ganchos encima de cada player
	playerSize = Vector2D(tP1->getW(), tP1->getH());
	drawingAreaHook1.x = tP1->getPos().getX() +(playerSize.getX()/2) - (drawingAreaHook1.w / 2);
	drawingAreaHook1.y = -drawingAreaHook1.h;
	drawingAreaHook2.x = tP2->getPos().getX() + (playerSize.getX() / 2) - (drawingAreaHook2.w / 2);
	drawingAreaHook2.y = -drawingAreaHook2.h;
	//Me quedo con las posiciones de los players para m�s tarde intercambiarles
	p1OriginalPos = tP1->getPos();
	p2OriginalPos = tP2->getPos();
	lastTick = SDL_GetTicks();
}

void HookAdversity::update()
{
	if (lastTick == 0)Start(); //Comienza la adversidad
	else {
		//impido que los players se muevan mientras dure la adversidad
		tP1->setVel(Vector2D(0, 0));
		tP2->setVel(Vector2D(0, 0));
		int advancedTicks = SDL_GetTicks() - lastTick;
		if (!catched) GoingDown(advancedTicks); //Bajo a por ellos
		else if (catched && !changedPositions) GoingUp(advancedTicks); // "Les saco de pantalla"
		else if (catched && changedPositions && !droped) GoingDown(advancedTicks); //les dejo en la posici�n del otro
		else if (catched && changedPositions && droped) GoingUp(advancedTicks); //saco los ganchos de pantalla
	}
}

//Muevo los ganchos cada uno a una velocidad concreta para que entren y salgan de pantalla
//a la vez y en una direcci�n concreta si me interesa bajar los ganchos o subirlos
void HookAdversity::Move(bool down, int advancedTicks) {
	if (down) {
		if (drawingAreaHook1.y + drawingAreaHook1.h < p1OriginalPos.getY() + playerSize.getY())
			drawingAreaHook1.y += (advancedTicks * hook1Vel);
		if (drawingAreaHook2.y + drawingAreaHook2.h < p2OriginalPos.getY() + playerSize.getY())
			drawingAreaHook2.y += (advancedTicks * hook2Vel);
	}
	else {
		if (drawingAreaHook1.y + drawingAreaHook1.h > 0)
			drawingAreaHook1.y -= (advancedTicks * hook1Vel);
		if (drawingAreaHook2.y + drawingAreaHook2.h > 0)
			drawingAreaHook2.y -= (advancedTicks * hook2Vel);
	}
}


//Este m�todo estaba pensado para mover a los player con los ganchos, pero por el sistema de colisiones y las animaciones se ha hecho de 
//otra forma
//void HookAdversity::SetContentPos(Transform* contentHook1, Transform* contentHook2) {
//	contentHook1->setPos(Vector2D(contentHook1->getPos().getX(), drawingAreaHook1.y + drawingAreaHook1.h - contentHook1->getH()));
//	contentHook2->setPos(Vector2D(contentHook2->getPos().getX(), drawingAreaHook2.y + drawingAreaHook2.h - contentHook2->getH()));
//}


//Subida de los ganchos
void HookAdversity::GoingUp(int advancedTicks) {
//muevo los ganchos hasta que salgan de pantalla 
	if (drawingAreaHook1.y + drawingAreaHook1.h <= 0 && drawingAreaHook2.y + drawingAreaHook2.h <= 0) {
		//intercambio de posiciones si es la primera ez que subo los ganchos
		if (!changedPositions) {
			Vector2D positionP1 = tP1->getPos();
			Vector2D positionP2 = tP2->getPos();
			tP1->setPos(positionP2);
			tP2->setPos(positionP1);
			changedPositions = true;
		}
		//Si es la segunda vez que los subo significa que la adversidad se acab�
		else {
			if(adversityMngr_ != nullptr)
			adversityMngr_->stopAdversity();
			multipleAdversityMngr_->stopAdversity(ecs::AdversityID::HookAdversity);
		}
	}
	else
		Move(false, advancedTicks);
}

void HookAdversity::GoingDown(int advancedTicks) {
	//Si los ganchos no llegaron a los players los muevo
	//Si llegaron reproduzco una animacion
	if (drawingAreaHook1.y + drawingAreaHook1.h >= p1OriginalPos.getY() + playerSize.getY() && drawingAreaHook2.y + drawingAreaHook2.h >= p2OriginalPos.getY() + playerSize.getY()) {
		/*if (SDL_GetTicks() - lastFrame > frameTime) {
			lastFrame = SDL_GetTicks();
			animationFrame--;
			if (animationFrame >= 0)
				clipArea.x = animationFrame * clipArea.w;
			else {
				animationFrame = 0;
				droped = true;
			}
		}*/
		//Si es la primera vez que bajo hago invisibles a los players
		if (!catched) {
			catched = true;
			tP1->setWH(0,0);
			tP2->setWH(0,0);
		}
		//Si es la segunda vez que bajo la adversidad se acabo y vuelvo a hacer visibles a los players
		else {
			droped = true;
			tP1->setWH(playerSize.getX(),playerSize.getY());
			tP2->setWH(playerSize.getX(),playerSize.getY());
		}
	}
	else
		Move(true, advancedTicks);
}


void HookAdversity::draw()
{
	hookTexture->render(drawingAreaHook1, clipArea);
	hookTexture->render(drawingAreaHook2, clipArea);
}

void HookAdversity::reset()
{
	lastTick = 0;
}