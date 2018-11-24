#include "Spaceship.h"

#include <iostream>


Spaceship::Spaceship(LTexture * texture, const int width, const int height)
{

	//Initialize the velocity
	mVelX = 0;
	mVelY = 0;

	mThisTexture = texture;

	mScreen_Width = width;
	mScreen_Height = height;

	mSizeX = mThisTexture->getWidth();
	mSizeY = mThisTexture->getHeight();

	//Initialize the position
	mPosX = (mScreen_Width - mSizeX) / 2;
	mPosY = (mScreen_Height - mSizeY) / 10 * 9;

}


bool Spaceship::handleEvent(SDL_Event& e)
{
	//If a key was pressed
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: mVelY -= DOT_VEL; break;
		case SDLK_DOWN: mVelY += DOT_VEL; break;
		case SDLK_LEFT: mVelX -= DOT_VEL; break;
		case SDLK_RIGHT: mVelX += DOT_VEL; break;
		}
	}
	//If a key was released
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		std::string debug_msg;

		//Adjust the velocity
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: mVelY += DOT_VEL; break;
		case SDLK_DOWN: mVelY -= DOT_VEL; break;
		case SDLK_LEFT: mVelX += DOT_VEL; break;
		case SDLK_RIGHT: mVelX -= DOT_VEL; break;
		case SDLK_w:
			debug_msg = "xpos:" + std::to_string(mPosX) \
				+ ", ypos:" + std::to_string(mPosY);

			debug_print(debug_msg);
			break;
		case SDLK_F12:
			return true;	// scene exit
			break;
		}
	}

	return false;
}

void Spaceship::move(float timeStep)
{
	//Move the dot left or right
	mPosX += mVelX * timeStep;

	//If the dot went too far to the left or right
	if (mPosX < 0)
	{
		mPosX = 0;
	}
	else if (mPosX > mScreen_Width - mSizeX)
	{
		mPosX = mScreen_Width - mSizeX;
	}

	//Move the dot up or down
	mPosY += mVelY * timeStep;

	//If the dot went too far up or down
	if (mPosY < 0)
	{
		mPosY = 0;
	}
	else if (mPosY > mScreen_Height - mSizeY)
	{
		mPosY = mScreen_Height - mSizeY;
	}
}

void Spaceship::render()
{
	//Show the dot
	mThisTexture->render((int)mPosX, (int)mPosY);
}

void Spaceship::debug_print(std::string aString)
{
	//Show the dot
	std::cout << aString << std::endl;
}

