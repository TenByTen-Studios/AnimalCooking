#pragma once
#include <SDL_ttf.h>
#include <string>

using namespace std;
class Font
{
private:
	TTF_Font* font = nullptr;
	
public:
	Font() {};
	Font(string filename, int size) { load(filename, size); }
	~Font() { clean(); }
	void load(string filename, int size) {
		font = TTF_OpenFont(filename.c_str(), size);
	}
	void clean() {
		if (font != nullptr) TTF_CloseFont(font);
		font = nullptr;
	}

	SDL_Surface* generateSurface(string text, SDL_Color color) const {
		return TTF_RenderText_Solid(font, text.c_str(), color);
	}
};
