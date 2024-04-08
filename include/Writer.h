#pragma once

#include "defines.h"

class Writer 
{
public:
	Writer();
	~Writer();

	void init();

	pair<int2, SDL_Texture*> getText(string text, COLOR color, int fontSize);

private:
	map <int, TTF_Font*> m_font; //Map of font int -> size, TTF_Font* -> font
	map <COLOR, SDL_Color> m_colors; 

	string m_fontLocation;
};