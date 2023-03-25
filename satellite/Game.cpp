#include "Game.h"
#include <glew.h>
#include "Texture.h"
#include "VertexArray.h"
#include "Shader.h"
#include <algorithm>
#include "Actor.h"
#include "SpriteComponent.h"
#include "Random.h"
#include "Renderer.h"
#include "Planet.h"
#include "Satellite.h"

#include "CircleComponent.h"

Game::Game() : mRenderer(nullptr), mIsRunning(true), mTicksCount(0), mUpdatingActors(false)
{}

bool Game::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}

	mRenderer = new Renderer(this);
	if (!mRenderer->Initialize(1024.0f, 768.0f))
	{
		SDL_Log("Failed to initialize renderer");
		delete mRenderer;
		mRenderer = nullptr;
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
	mRenderer->Draw();
}

void Game::Shutdown()
{
	UnloadData();
	if (mRenderer) {
		mRenderer->Shutdown();
	}
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

void Game::AddGravity(class GravityComponent* gravity)
{
	mGravityComponents.push_back(gravity);
}

void Game::RemoveGravity(class GravityComponent* gravity)
{
	auto iter = std::find(mGravityComponents.begin(), mGravityComponents.end(), gravity);
	mGravityComponents.erase(iter);
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

void Game::LoadData()
{
	Satellite* satellite = new Satellite(this);
	Planet* planet = new Planet(this);
}

void Game::UnloadData()
{
	while (!mActors.empty())
	{
		delete mActors.back();
	}
	if (mRenderer) {
		mRenderer->UnloadData();
	}
}