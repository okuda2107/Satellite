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

	void AddSprite(class SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);

	void AddGravity(class GravityComponent* gravity);
	void RemoveGravity(class GravityComponent* gravity);

	std::vector<class GravityComponent*> mGravity;

	void LoadData();
	void UnLoadData();

	SDL_Renderer* GetRenderer() { return mRenderer; }

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

};