#include "Game.h"
#include "Actor.h"
#include <vector>
#include <algorithm>
#include "SpriteComponent.h"
#include "CircleComponent.h"
#include "StartActor.h"
#include "Satellite.h"
#include "Planet.h"

Game::Game() : mWindow(nullptr), mRenderer(nullptr), mIsRunning(true), mTicksCount(0), mUpdatingActors(false), mSatellite(nullptr), mScreenSize(1024,768), mWorldSize(2048, 1536)
{}

bool Game::Initialize()
{
	if (int sdlResult = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
	{
		SDL_Log("Failed to Initialize the SDL:%s", SDL_GetError());
		return false;
	}
	mWindow = SDL_CreateWindow(
		"Game Programming in C++",
		20,
		20,
		1024,
		768,
		0);
	if (!mWindow)
	{
		SDL_Log("Failed to Create the Window:%s", SDL_GetError());
		return false;
	}
	mRenderer = SDL_CreateRenderer(
		mWindow,
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);

	if (IMG_Init(IMG_INIT_PNG) == 0)
	{
		SDL_Log("Failed to Initialize the SDL_image:%s", SDL_GetError());
		return false;
	}

	LoadData();

	mTicksCount = SDL_GetTicks();

	return true;
}

void Game::RunLoop()
{
	while (mIsRunning)
	{
		ProcessInput();
		UpdateGame();
		GenerateOutput();
	}
}

void Game::ProcessInput()
{
	SDL_Event mEvent;
	while (SDL_PollEvent(&mEvent))
	{
		switch (mEvent.type)
			case SDL_QUIT:
				mIsRunning = false;
				break;
	}
	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_ESCAPE])
	{
		mIsRunning = false;
	}

	mUpdatingActors = true;
	for (auto actor : mActors)
	{
		actor->ProcessInput(state);
	}
	mUpdatingActors = false;
}

void Game::UpdateGame()
{
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16));
	float deltatime = (SDL_GetTicks() - mTicksCount) / 1000.0f;
	if (deltatime > 0.05f)
	{
		deltatime = 0.05f;
	}
	mTicksCount = SDL_GetTicks();
	
	GameEvent();

	UpdateActors(deltatime);
}

void Game::GenerateOutput()
{
	SDL_SetRenderDrawColor(
		mRenderer,
		79,
		79,
		79,
		255
	);
	SDL_RenderClear(mRenderer);

	for (auto sprites : mSprites)
	{
		sprites->Draw(mRenderer);
	}

	SDL_RenderPresent(mRenderer);
}

void Game::Shutdown()
{
	UnLoadData();
	IMG_Quit();
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}

void Game::AddActor(class Actor* actor)
{
	if (mUpdatingActors)
	{
		mPendingActors.push_back(actor);
	}
	else
	{
		mActors.push_back(actor);
	}
}

void Game::RemoveActor(class Actor* actor)
{
	auto iter = find(mPendingActors.begin(), mPendingActors.end(), actor);
	if (iter != mPendingActors.end())
	{
		std::iter_swap(iter, mPendingActors.end() - 1);
		mPendingActors.pop_back();
	}
	iter = find(mActors.begin(), mActors.end(), actor);
	if (iter != mActors.end())
	{
		std::iter_swap(iter, mActors.end() - 1);
		mActors.pop_back();
	}
}

void Game::UpdateActors(float deltatime)
{
	mUpdatingActors = true;
	for (auto actor : mActors)
	{
		if (actor->GetState() != Actor::EDead)
		{
			actor->Update(deltatime);
		}
	}
	mUpdatingActors = false;

	for (auto pending : mPendingActors)
	{
		mActors.emplace_back(pending);
	}
	mPendingActors.clear();

	std::vector<Actor*> deadActors;
	for (auto actor : mActors)
	{
		if (actor->GetState() == Actor::EDead)
		{
			deadActors.emplace_back(actor);
		}
	}
	for (auto actor : deadActors)
	{
		delete actor;
	}
}

void Game::GameEvent()
{


	for (size_t i = 0;i < mColider.size() - 1;i++) 
	{
		for (size_t j = i + 1;j < mColider.size();j++)
		{
			if (Intersect(*mColider[i], *mColider[j]))
			{
				if (mColider[i]->GetRadius() < mColider[j]->GetRadius()) 
				{
					*mColider[j] += *mColider[i];
					mColider[i]->GetOwner()->SetState(Actor::EDead);
				}
				else 
				{
					*mColider[i] += *mColider[j];
					mColider[j]->GetOwner()->SetState(Actor::EDead);
				}
			}
		}
	}
}

void Game::AddSprite(class SpriteComponent* sprite)
{
	int myDrawOrder = sprite->GetDrawOrder();
	auto iter = mSprites.begin();
	for (; iter != mSprites.end(); ++iter)
	{
		if ((*iter)->GetDrawOrder() > myDrawOrder)
		{
			break;
		}
	}
	mSprites.insert(iter, sprite);
}

void Game::RemoveSprite(class SpriteComponent* sprite)
{
	auto iter = std::find(mSprites.begin(), mSprites.end(), sprite);
	mSprites.erase(iter);
}

void Game::AddGravity(class GravityComponent* gravity)
{
	mGravity.push_back(gravity);
}

void Game::RemoveGravity(class GravityComponent* gravity)
{
	auto iter = std::find(mGravity.begin(), mGravity.end(), gravity);
	mGravity.erase(iter);
}

void Game::AddColider(class CircleComponent* colision)
{
	mColider.push_back(colision);
}

void Game::RemoveColider(CircleComponent* colision)
{
	auto iter_collison = std::find(mColider.begin(), mColider.end(), colision);
	mColider.erase(iter_collison);
}

SDL_Texture* Game::GetTexture(const std::string& filename)
{
	SDL_Texture* tex = nullptr;
	auto iter = mTextures.find(filename);
	if (iter != mTextures.end())
	{
		tex = iter->second;
	}
	else
	{
		SDL_Surface* surf = IMG_Load(filename.c_str());
		if (!surf)
		{
			SDL_Log("Failed to Load Surface:%s", filename.c_str());
			return nullptr;
		}
		tex = SDL_CreateTextureFromSurface(mRenderer, surf);
		SDL_FreeSurface(surf);
		if (!tex)
		{
			SDL_Log("Failed to Convert Surface into Texture:%s", filename.c_str());
			return nullptr;
		}
		mTextures.emplace(filename, tex);
	}
	return tex;
}

void Game::LoadData()
{
	for (int i = 0; i < 10; i++)
	{
		Planet* pl = new Planet(this);
	}
	
	Planet* plmax = new Planet(this);
	plmax->SetFlag(true);
	
	mSatellite = new Satellite(this);

}

void Game::UnLoadData()
{
	while (!mSprites.empty())
	{
		delete mSprites.back();
	}
	while (!mActors.empty())
	{
		delete mActors.back();
	}
	for (auto i : mTextures)
	{
		SDL_DestroyTexture(i.second);
	}
	mTextures.clear();
	//erase()はメモリの解放はしないが、メモリの内容をnullにする
}