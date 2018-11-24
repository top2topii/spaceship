/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and, strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

#include "Spaceship.h"
#include "LTexture.h"
#include "LTimer.h"
#include "SceneManager.h"

//Screen dimension constants
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 800;



int main(int argc, char* args[])
{
	SceneManager scene_manager(SCREEN_WIDTH, SCREEN_HEIGHT);

	scene_manager.changeScene(ID_INTRO_SCENE);

	return 0;
}