#pragma once
#include "TextField.h"

class ConfiglessTTF : public TextField {
public:
	ConfiglessTTF();
	~ConfiglessTTF();
	void init(SDL_Rect rect, int font, int color, string background);
	SDL_Rect getRect();
	void setRect(SDL_Rect rect);
};