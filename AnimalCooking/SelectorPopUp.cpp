#include "SelectorPopUp.h"

SelectorPopUp::~SelectorPopUp()
{
	for (auto it : pool_) {
		delete it;
	}
}
//Checkea para la pool correspondiente si ha colisionado con el jugador
//en la direcci�n indicada. En caso positivo, le pasa al Selector del
//jugador el objeto que puede ser utilizado.
void SelectorPopUp::update()
{
	for (auto it : pool_) {
		if(Collisions::collidesWithRotation(tr1_->getPos())
	}
}
