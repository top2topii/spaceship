#include "GamerunScene.h"

GamerunScene::GamerunScene(SceneManager* scene_manager) : mSceneManager(scene_manager)
{
	mSceneTexture = mSceneManager->mSceneTexture;
	mRenderer = mSceneManager->mRenderer;
	mWindow = mSceneManager->mWindow;

	mScreenWidth = mSceneManager->mScreenWidth;
	mScreenHeight = mSceneManager->mScreenHeight;
}

void GamerunScene::start()
{
}

void GamerunScene::free()
{
	if (mSceneTexture) {
		mSceneTexture->free();
	}
}

void GamerunScene::handleEvent(SDL_Event& e)
{

}