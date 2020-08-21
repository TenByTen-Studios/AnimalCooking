#include "PidgeonAdversity.h"
#include "MultipleAdversityManager.h"
#include "TimerViewer.h"

PidgeonAdversity::PidgeonAdversity(MultipleAdversityManager* mam) :Adversity(mam)
{

	positions.push_back(false);
	positions.push_back(false);
	positions.push_back(false);
	positions.push_back(false);

	coming_ = false;
	standing_ = false;
	leaving_ = false;
	durationTimer_ = new Timer();
	durationTimer_->setTime(3000);
	GETCMP2(SDLGame::instance()->getTimersViewer(), TimerViewer)->addTimer(durationTimer_);

	drawingTexture_ = SDLGame::instance()->getTextureMngr()->getTexture(Resources::PidgeonAdversity);

	drawingArea_.x = 0;
	drawingArea_.y = 0;
	drawingArea_.w = SDLGame::instance()->getWindowWidth() * 1.3 / 4;
	drawingArea_.h = SDLGame::instance()->getWindowHeight() * 2/ 3;

	column = 0;

	angle = 0;

	lastFrame = 0;
	frameDuration = 200;

	clipArea_.x = 512 * column;
	clipArea_.y = 0;
	clipArea_.w = 512;
	clipArea_.h = 512;

	numPidgeons = 3;
	pidgeonsSeen = 0;
}

void PidgeonAdversity::update()
{
	durationTimer_->update();
	locateFrame();
	//Cuando este en estos intervalos de tiempo llamo a move para que calcule su posicion exacta y que entre y salga de pantalla
	if (durationTimer_->getProgress() < 0.10)move(0.10,0.10);
	else if (durationTimer_->getProgress() > 0.90)move(1,0.10);

	//La animacion va segun el timer, si hemos visitado todas las columnas significa que hemos terminado con esta paloma
	if (column >= 20) {
		pidgeonFinished();
	}
}


void PidgeonAdversity::draw()
{
	clipArea_.x = column * 512;
	clipArea_.y = 0;
	drawingTexture_->render(drawingArea_, angle, clipArea_,flipVar);
}

void PidgeonAdversity::reset()
{
	durationTimer_->timerReset();
	coming_ = false;
	standing_ = false;
	leaving_ = false;
	column = 0;
	pidgeonsSeen = 0;
	positions.at(0) = false; positions.at(1) = false;
	positions.at(2) = false; positions.at(3) = false;
}

void PidgeonAdversity::start()
{
	locatePidgeon();
	column = 0;
	coming_ = true;
	durationTimer_->timerReset();
	durationTimer_->timerStart();
}



void PidgeonAdversity::locatePidgeon()
{
	//Me indica si es horizontal o vertical su posicion
	int a = SDLGame::instance()->getRandGen()->nextInt() % 2;
	//Me indica si esta izquierda(0)/derecha(1) o abajo(0)/ arriba(1)
	int b = SDLGame::instance()->getRandGen()->nextInt() % 2;
	int pos = posibleLocation(a, b);
	//Mientras la posicion que quiero ocupar ya haya sido usada busco otra
	while (positions.at(pos)) {
		a = SDLGame::instance()->getRandGen()->nextInt() % 2;
		b = SDLGame::instance()->getRandGen()->nextInt() % 2;
		pos = posibleLocation(a, b);
	}
	//ARRIBA
	if (pos == 0) {
		drawingArea_.x = SDLGame::instance()->getRandGen()->nextInt(0, SDLGame::instance()->getWindowWidth() - drawingArea_.w);
		drawingArea_.y = 0;
	}
	//DERECHA
	else if (pos == 1) {
		drawingArea_.x = SDLGame::instance()->getWindowWidth() - drawingArea_.w;
		drawingArea_.y = SDLGame::instance()->getRandGen()->nextInt(0, SDLGame::instance()->getWindowHeight() - drawingArea_.h);
	}
	//ABAJO
	else if (pos == 2) {
		drawingArea_.x = SDLGame::instance()->getRandGen()->nextInt(0, SDLGame::instance()->getWindowWidth() - drawingArea_.w);
		drawingArea_.y = SDLGame::instance()->getWindowHeight() - drawingArea_.h;
	}
	//IZQUIERDA
	else if (pos == 3) {
		drawingArea_.x = 0;
		drawingArea_.y = SDLGame::instance()->getRandGen()->nextInt(0, SDLGame::instance()->getWindowHeight() - drawingArea_.h);
	}
	angle = 180 + (90 * pos);
	positions.at(pos) = true;
	lastPidgeon.direction = pos;
	lastPidgeon.posX = drawingArea_.x;
	lastPidgeon.posY = drawingArea_.y;
}

int PidgeonAdversity::posibleLocation(int a, int b)
{
	int pos = 0;
	if (a == 0 && b == 1) pos = 0;       //Arriba
	else if (a == 1 && b == 1)  pos = 1; //Derecha
	else if (a == 0 && b == 0)  pos = 2; //Abajo
	else if (a == 1 && b == 0)  pos = 3; //Izquierda

	return pos;
}

int PidgeonAdversity::locateFrame()
{
	column = (durationTimer_->getProgress() * 21);
	return 0;
}

//Una vez una paloma ha terminado, si quedan mas las reseteo todo y las llamo, sino termina mi adversidad
void PidgeonAdversity::pidgeonFinished()
{
	column = 0;
	pidgeonsSeen++;
	if (pidgeonsSeen >= numPidgeons)
		multipleAdversityMngr_->stopAdversity(ecs::AdversityID::PidgeonAdversity);
	else {

		if (pidgeonsSeen % 2 == 1) flipVar = SDL_FLIP_HORIZONTAL;
		else flipVar = SDL_FLIP_NONE;

		locatePidgeon();
		durationTimer_->timerReset();
		durationTimer_->timerStart();
	}
}


//Muevo a la paloma hacia el centro de la pantalla o hago que salga de esta
void PidgeonAdversity::move(double c, double div)
{
	double a = ((c-durationTimer_->getProgress())/div);
	if (c > 0.5) a = 1 - a;
	switch (lastPidgeon.direction) {
	case 0:
		drawingArea_.y = lastPidgeon.posY - (a * drawingArea_.h);
	break;
	case 1:
		drawingArea_.x = lastPidgeon.posX + (a * drawingArea_.w);
		break;
	case 2:
		drawingArea_.y = lastPidgeon.posY + (a * drawingArea_.h);
		break;
	case 3:
		drawingArea_.x = lastPidgeon.posX - (a * drawingArea_.w);
		break;
	}
}