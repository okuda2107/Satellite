#include "Actor.h"
#include "Game.h"
#include "Component.h"
#include <algorithm>

Actor::Actor(class Game* game) : mGame(game), mPosition(Vector2::Zero), mScale(1.0f), mActorGravity(nullptr)
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

void Actor::ActorInput(const uint8_t* keyState)
{}

void Actor::Update(float deltatime)
{
	if (mState == State::EActive)
	{
		ComputeWorldTransform();
		UpdateComponent(deltatime);
		UpdateActor(deltatime);
		ComputeWorldTransform();
	}
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

//�傫�������珇�ɓ����Ă���
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

void Actor::ComputeWorldTransform()
{
	if (mRecomputeWorldTransform)
	{
		mRecomputeWorldTransform = false;
		// scaling, rotation, translation
		mWorldTransform = Matrix4::CreateScale(mScale);
		mWorldTransform *= Matrix4::CreateRotationZ(mRotation);
		mWorldTransform *= Matrix4::CreateTranslation(Vector3(mPosition.x, mPosition.y, 0.0f));
		for (auto comp : mComponents)
		{
			comp->OnUpdateWorldTransform();
		}

	}
}
