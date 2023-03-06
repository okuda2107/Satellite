#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <vector>
#include <unordered_map>
#include <string>

class Game
{
public:
	Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();

	void AddActor(class Actor* actor);
	void RemoveActor(class Actor* actor);

	void AddGravity(class GravityComponent* gravity);
	void RemoveGravity(class GravityComponent* gravity);

	void AddColider(class CircleComponent* colision);
	void RemoveColider(class CircleComponent* colision);

	std::vector<class GravityComponent*> mGravity;
	std::vector<class CircleComponent*>mColider;

	void GameEvent();

	void LoadData();
	void UnloadData();

	class Renderer* GetRenderer() { return mRenderer; }
private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	void UpdateActors(float deltatime);

	class Renderer* mRenderer;
	bool mIsRunning;
	Uint32 mTicksCount;

	std::vector<class Actor*> mActors;
	std::vector<class Actor*> mPendingActors;

	bool mUpdatingActors;
};
