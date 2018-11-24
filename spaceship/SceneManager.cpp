#include "SceneManager.h"
#include "IntroScene.h"
#include "GamerunScene.h"

#include "SDL.h"
#include "SDL_image.h"

SceneManager::SceneManager(const int screen_width, const int screen_height): mScreenWidth(screen_height), mScreenHeight(screen_height){

	//Initialization flag
	mSucessInit = true;
	mWindow = NULL;
	mRenderer = NULL;

	mScene = NULL;
	mOldScene = NULL;


	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		mSucessInit = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		mWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mScreenWidth, mScreenHeight, SDL_WINDOW_SHOWN);
		if (mWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			mSucessInit = false;
		}
		else
		{
			//Create renderer for window
			mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
			if (mRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				mSucessInit = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					mSucessInit = false;
				}

				mSceneTexture = new LTexture(mRenderer);
			}
		}
	}
}


void SceneManager::changeScene(short id) {

	if (mOldScene) {
		delete mOldScene;
	}

	if (id == ID_INTRO_SCENE) {
		mScene = new IntroScene(this);
		mOldScene = mScene;
	}
	else if (id == ID_GAMERUN_SCENT) {
		mScene = new GamerunScene(this);
		mOldScene = mScene;
	}

	if (mScene) {
		// TODO: make the scene visible.
		mScene->start();
	}
}

SceneManager::~SceneManager() {
	//Free loaded images
	mSceneTexture->free();

	//Destroy window	
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	mWindow = NULL;
	mRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();

}
