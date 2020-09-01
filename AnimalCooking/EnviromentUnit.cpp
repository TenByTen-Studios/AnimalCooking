#include "EnviromentUnit.h"
#include "SDL_macros.h"
#include"Collisions.h"

EnviromentUnit::EnviromentUnit(Vector2D pos, double w, double h, Transform* tP1, Transform* tP2, PlayerController* pC1, PlayerController* pC2, EnviromentControl* envC) : pos(pos), width(w), height(h), tP1(tP1), tP2(tP2),
pC1(pC1), pC2(pC2), affectingP1(false), affectingP2(false), playerAffectedNow(-1), envC(envC)
{
}

void EnviromentUnit::render() const
{
	SDL_Rect rect = RECT(pos.getX(), pos.getY(), width, height);
	texture->render(rect);
}




Snow::Snow(Vector2D pos, double width, double height, Transform* tP1, Transform* tP2, PlayerController* pC1, PlayerController* pC2, EnviromentControl* envC) :
	EnviromentUnit(pos, width, height, tP1, tP2, pC1, pC2, envC)
{
	texture = SDLGame::instance()->getTextureMngr()->getTexture(Resources::Fregadero);
}


void Snow::update()
{
	if (!affectingP1 && Collisions::collides(pos, width, height, tP1->getPos(), tP1->getW(), tP1->getH())) {
		playerAffectedNow = 0;
		act();
		affectingP1 = true;
	}
	else if (affectingP1 && !Collisions::collides(pos, width, height, tP1->getPos(), tP1->getW(), tP1->getH())) {
		playerAffectedNow = -1;
		pC1->resetSpeed();
		affectingP1 = false;
	}
	if (!affectingP2 && Collisions::collides(pos, width, height, tP2->getPos(), tP2->getW(), tP2->getH())) {
		playerAffectedNow = 1;
		act();
		affectingP2 = true;
	}
	else if (affectingP2 && !Collisions::collides(pos, width, height, tP2->getPos(), tP2->getW(), tP2->getH())) {
		playerAffectedNow = -1;
		pC2->resetSpeed();
		affectingP2 = false;
	}
}

void Snow::act()
{
	PlayerController* pC = nullptr;
	if (playerAffectedNow == 0)pC = pC1;
	else pC = pC2;
	pC->setSpeed(0.3);

}



Ice::Ice(Vector2D pos, double width, double height, Transform* tP1, Transform* tP2, PlayerController* pC1, PlayerController* pC2, EnviromentControl* envC) :
	EnviromentUnit(pos, width, height, tP1, tP2, pC1, pC2, envC)
{
	texture = SDLGame::instance()->getTextureMngr()->getTexture(Resources::Dish);
}

void Ice::act()
{
	Transform* p = nullptr;
	if (playerAffectedNow == 0) {
		p = tP1;
		Vector2D vel;
		vel.setX(envC->getPlayerForceX(0) * (config::PLAYER_SPEED * SDLGame::instance()->getCasillaX() / 60)/2.75);
		vel.setY(envC->getPlayerForceY(0) * (config::PLAYER_SPEED * SDLGame::instance()->getCasillaY() / 60)/2.75);
		p1Pos = p->getPos();
		p1Pos = p1Pos + vel;
	}
	else {
		p = tP2;
		Vector2D vel;
		vel.setX(envC->getPlayerForceX(1) * (config::PLAYER_SPEED * SDLGame::instance()->getCasillaX() / 60) / 2.75);
		vel.setY(envC->getPlayerForceY(1) * (config::PLAYER_SPEED * SDLGame::instance()->getCasillaY() / 60) / 2.75);
		p2Pos = p->getPos();
		p2Pos = p2Pos + vel;
	}


}

void Ice::update()
{

	//PARA EL PLAYER 1
	if (!affectingP1 && Collisions::collides(pos, width, height, tP1->getPos(), tP1->getW(), tP1->getH())) {
		envC->enterIceZone(0,tP1->getVel());
		affectingP1 = true;
		playerAffectedNow = 0;
		p1Pos = tP1->getPos();
	}
	else if (affectingP1 && Collisions::collides(pos, width, height, tP1->getPos(), tP1->getW(), tP1->getH())) {
		tP1->setPos(p1Pos);
		playerAffectedNow = 0;
		envC->playerIsMoving(0,tP1->getVel());
		act();
		tP1->setPos(p1Pos);
	}
	else if (affectingP1 && !Collisions::collides(pos, width, height, tP1->getPos(), tP1->getW(), tP1->getH())) {
		playerAffectedNow = -1;
		affectingP1 = false;
		envC->exitedIceZone(0);

	}


	//PARA EL PLAYER 2
	if (!affectingP2 && Collisions::collides(pos, width, height, tP2->getPos(), tP2->getW(), tP2->getH())) {
		envC->enterIceZone(1, tP2->getVel());
		affectingP2 = true;
		playerAffectedNow = 1;
		p2Pos = tP2->getPos();
	}
	else if (affectingP2 && Collisions::collides(pos, width, height, tP2->getPos(), tP2->getW(), tP2->getH())) {
		tP2->setPos(p2Pos);
		playerAffectedNow = 1;
		envC->playerIsMoving(1, tP2->getVel());
		act();
		tP2->setPos(p2Pos);
	}
	else if (affectingP2 && !Collisions::collides(pos, width, height, tP2->getPos(), tP2->getW(), tP2->getH())) {
		playerAffectedNow = -1;
		affectingP2 = false;
		envC->exitedIceZone(1);
	}
}
