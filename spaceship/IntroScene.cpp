#include "IntroScene.h"
#include "LTimer.h"
#include "Spaceship.h"
#include "SceneManager.h"

#include <iostream>


IntroScene::IntroScene(SceneManager* scene_manager): mSceneManager(scene_manager)
{
	mSceneTexture = mSceneManager->mSceneTexture;
	mRenderer = mSceneManager->mRenderer;
	mWindow = mSceneManager->mWindow;

	mScreenWidth = mSceneManager->mScreenWidth;
	mScreenHeight = mSceneManager->mScreenHeight;
}

void IntroScene::start()
{
	// for info
	std::cout << "In IntroScene" << std::endl;

	//Main loop flag
	bool quit = false;
	bool next = false;

	//Event handler
	SDL_Event e;

	//Keeps track of time between steps
	LTimer stepTimer;

	if (loadMedia()) {

	}
	else {
		printf("load Media Failed!");
		exit(1);
	}

	Spaceship myship(mSceneTexture, mScreenWidth, mScreenHeight);

	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			//Handle input for the dot
			//bullet.handleEvent(e);
			if (myship.handleEvent(e)) {
				// scene exit
				quit = true;
				next = true;
			}
		}

		//Calculate time step
		float timeStep = stepTimer.getTicks() / 1000.f;

		//Move for time step
		//bullet.move(timeStep);
		myship.move(timeStep);

		//Restart step timer
		stepTimer.start();

		//Clear screen
		SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(mRenderer);

		//Render dot
		//bullet.render();
		myship.render();

		//Update screen
		SDL_RenderPresent(mRenderer);
	}

	if (next) nextScene();
}

bool IntroScene::loadMedia() {
	//Loading success flag
	bool success = true;

	//Load dot texture
	if (!mSceneTexture->loadFromFile("data/images/pixel_std_sp.png"))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}

	return success;
}

void IntroScene::free()
{
	if (mSceneTexture) {
		mSceneTexture->free();
	}
}

void IntroScene::nextScene()
{
	mSceneManager->nextScene(ID_INTRO_SCENE);
}

void IntroScene::handleEvent(SDL_Event& e)
{
}

IntroScene::~IntroScene()
{
	free();
}