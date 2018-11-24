#pragma once

#include "Scene.h"
#include "LTexture.h"

enum {
	ID_INTRO_SCENE,
	ID_GAMERUN_SCENE
};

class SceneManager {
public:
	SceneManager(const int screen_width, const int screen_height);
	~SceneManager();
	void changeScene(short id);
	void nextScene(short id);	// 해당 씬이 다음 씬으로 넘어갈 것을 요청함.

	//The window we'll be rendering to
	SDL_Window* mWindow;

	//The window renderer
	SDL_Renderer* mRenderer;

	//Scene textures
	LTexture *mSceneTexture;

	const int mScreenWidth;
	const int mScreenHeight;

	Scene* mScene;
	Scene* mOldScene;


private:

	bool mSucessInit;
};
