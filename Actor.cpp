#include "Actor.h"
#include "Game.h"
#include "Component.h"
#include <algorithm>

Actor::Actor(class Game* game) : mGame(game), mPosition(0, 0), mScale(1.0f), mRotation(0.0f)
{
	mGame->AddActor(this);
}

Actor::~Actor()
{
	mGame->RemoveActor(this);

	while (!mComponents.empty())
	{
		delete mComponents.back();
	}
}

void Actor::ProcessInput(const uint8_t* keystate)
{
	if (mState == EActive)
	{
		for (auto comp : mComponents)
		{
			comp->ProcessInput(keystate);
		}
		ActorInput(keystate);
	}
}

void Actor::Update(float deltatime)
{
	UpdateComponent(deltatime);
	UpdateActor(deltatime);
}

void Actor::UpdateComponent(float deltatime)
{
	for (auto component : mComponents)
	{
		component->Update(deltatime);
	}
}

void Actor::UpdateActor(float deltatime)
{}

void Actor::AddComponent(class Component* component)
{
	int updateOrder = component->GetUpdateOrder();
	auto iter = mComponents.begin();
	for (; iter != mComponents.end(); ++iter)
	{
		if (updateOrder < (*iter)->GetUpdateOrder())
		{
			break;
		}
	}
	mComponents.insert(iter, component);
}

void Actor::RemoveComponent(class Component* component)
{
	auto iter = std::find(mComponents.begin(), mComponents.end(), component);
	if (iter != mComponents.end())
	{
		mComponents.erase(iter);
	}
}