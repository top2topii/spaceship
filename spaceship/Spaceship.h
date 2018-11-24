#pragma once

#include <string>
#include <SDL.h>
#include <SDL_image.h>

#include "LTexture.h"

class Spaceship
{
public:
	//The dimensions of the dot
	static const int DOT_WIDTH = 20;
	static const int DOT_HEIGHT = 20;

	//Maximum axis velocity of the dot
	static const int DOT_VEL = 320;

	//Initializes the variables
	Spaceship(LTexture *, const int, const int);

	//Takes key presses and adjusts the dot's velocity
	bool handleEvent(SDL_Event& e);

	//Moves the dot
	void move(float timeStep);

	//Shows the dot on the screen
	void render();

	void debug_print(std::string);

private:
	float mPosX, mPosY;
	float mVelX, mVelY;
	int mScreen_Width;
	int mScreen_Height;

	int mSizeX, mSizeY;

	LTexture *mThisTexture;
};

