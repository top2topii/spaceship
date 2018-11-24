#pragma once
#include "Scene.h"
#include "SceneManager.h"

#include "SDL.h"

class GamerunScene :
	public Scene
{
public:

	GamerunScene(SceneManager* scene_manager);
	~GamerunScene();

	virtual void start();
	virtual void free();

	void handleEvent(SDL_Event &e);

	SceneManager* mSceneManager;

	//The window we'll be rendering to
	SDL_Window* mWindow;

	//The window renderer
	SDL_Renderer* mRenderer;

	//Scene textures
	LTexture *mSceneTexture;

	int mScreenWidth;
	int mScreenHeight;
};

