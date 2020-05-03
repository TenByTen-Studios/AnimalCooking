#include "LevelViewer.h"
#include "SDL_macros.h"
#include<string>
void LevelViewer::draw()
{
	int timeSpan = SDLGame::instance()->getTime() - startedTick;

	if (timeSpan >= levelTime)
	{
		int lv = SDLGame::instance()->getCurrentLevel() - 1;
		string lvs = "level " + std::to_string(lv);
		Texture(SDLGame::instance()->getRenderer(), lvs,
			SDLGame::instance()->getFontMngr()->getFont(Resources::FontId::ARIAL12), hex2sdlcolor(
				"#FFFFFFFF")).render(RECT(
					SDLGame::instance()->getWindowWidth() - 3 * casilla,
					casilla * 3,
					2 * casilla,
					casilla), 7);
	}
	if (timeSpan >= scoreTime)
		Texture(SDLGame::instance()->getRenderer(), "12 points",
			SDLGame::instance()->getFontMngr()->getFont(Resources::FontId::ARIAL12), hex2sdlcolor(
				"#FFFFFFFF")).render(RECT(
					SDLGame::instance()->getWindowWidth() - 3.25 * casilla
					,
					casilla * 4,
					2 * casilla,
					casilla), 7);
	if (timeSpan >= barTime) {
		int w = 10 * casilla;
		int h = casilla;
		bar->render(RECT(casilla, casilla, w, h));
		double osp = casilla + (oneStarPerc / 100) * w - casilla / 10;
		double tsp = casilla + (twoStarPerc / 100) * w - casilla / 10;
		double thsp = casilla + (threeStarPerc / 100) * w - casilla / 10;
		limitSign->render(RECT(osp, casilla, casilla / 10, casilla / 5));
		limitSign->render(RECT(tsp, casilla, casilla / 10, casilla / 5));
		limitSign->render(RECT(thsp, casilla, casilla / 10, casilla / 5));
		double starSize = casilla / 3;
		//casilla - casilla / 2.5 porque está en la y casilla y casilla/2.5 es la mitad de casilla/5
		star->render(RECT(osp - starSize/2, casilla - casilla / 2.5, starSize, starSize));
		
		star->render(RECT(tsp - starSize, casilla - casilla / 2.5, starSize, starSize));
		star->render(RECT(tsp , casilla - casilla / 2.5, starSize, starSize));

		star->render(RECT(thsp - 3*starSize / 2, casilla - casilla / 2.5, starSize, starSize));
		star->render(RECT(thsp - starSize / 2, casilla - casilla / 2.5, starSize, starSize));
		star->render(RECT(thsp + starSize / 2, casilla - casilla / 2.5, starSize, starSize));


	}

}

void LevelViewer::init()
{
	bar = SDLGame::instance()->getTextureMngr()->getTexture(Resources::SliderBackground);
	star = SDLGame::instance()->getTextureMngr()->getTexture(Resources::Star);
	limitSign = SDLGame::instance()->getTextureMngr()->getTexture(Resources::LimitSign);
	casilla = SDLGame::instance()->getCasillaLength();
}
