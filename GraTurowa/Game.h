#pragma once

#include "Hero.h"

using namespace sf;

class Game
{
public:
	int Mx = 1408;
	int My = 1408;
	int Kratka = 128;
	float Q = 1.0;

	int dCx = 0;
	int dCy = 0;

	Sprite kratka;
	Texture krat;

	Sprite menu;
	Texture m;

	Sprite kursor;
	Texture t;

	Sprite sprite;
	Texture texture;

	Sprite background;
	Texture back1;
	Texture back2;

	Text text;
	Font font;

	Sprite Border;
	Texture border1;
	Texture border2;
	
	Game();
	~Game();

	void Move(int x, int y);

};


