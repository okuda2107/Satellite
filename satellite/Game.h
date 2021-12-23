#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <vector>
#include <unordered_map>
#include <string>
#include "Math.h"

class Game
{
public:
	Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();

	void AddActor(class Actor* actor);
	void RemoveActor(class Actor* actor);

	void AddSprite(class SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);

	void AddGravity(class GravityComponent* gravity);
	void RemoveGravity(class GravityComponent* gravity);

	void AddColider(class CircleComponent* colision);
	void RemoveColider(class CircleComponent* colision);

	std::vector<class GravityComponent*> mGravity;
	std::vector<class CircleComponent*>mColider;

	void GameEvent();

	void LoadData();
	void UnLoadData();

	SDL_Renderer* GetRenderer() { return mRenderer; }
	std::vector<class Actor*>& GetActors() { return mActors; }
	class Satellite* GetSatellite() { return mSatellite; }
	Vector2* GetScreenSize() { return &mScreenSize; }
	Vector2* GetWorldSize() { return &mWorldSize; }

	SDL_Texture* GetTexture(const std::string& filename);
private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	void UpdateActors(float deltatime);

	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	bool mIsRunning;
	Uint32 mTicksCount;

	std::vector<class Actor*> mActors;
	std::vector<class Actor*> mPendingActors;

	bool mUpdatingActors;

	std::unordered_map<std::string, SDL_Texture*> mTextures;
	std::vector<class SpriteComponent*> mSprites;

	class Satellite* mSatellite;

	Vector2 mWorldSize;//
	Vector2 mScreenSize;
};