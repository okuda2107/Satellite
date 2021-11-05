#pragma once
#include <vector>
#include "Math.h"
#include <cstdint>

class Actor
{
public:
	enum State
	{
		EActive,
		EPaused,
		EDead
	};

	Actor(class Game* game);
	~Actor();

	void ProcessInput(const uint8_t* keystate);
	virtual void ActorInput(const uint8_t* keystate)
	{}

	void Update(float deltatime);
	void UpdateComponent(float deltatime);
	virtual void UpdateActor(float deltatime);

	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);

	class Game* GetGame() { return mGame; }
	Vector2 GetPosition() { return mPosition; }
	float GetScale() { return mScale; }
	float GetRotation() { return mRotation; }
	State GetState() { return mState; }
	Vector2 GetForward() { return Vector2(Math::Cos(mRotation), -Math::Sin(mRotation)); }
	float GetMass() { return mMass; }

	void SetState(State state) { mState = state; }
	void SetScale(float scale) { mScale = scale; }
	void SetPosition(Vector2 pos) { mPosition = pos; }
	void SetMass(float mass) { mMass = mass; }
private:
	Game* mGame;
	Vector2 mPosition;
	float mScale;
	State mState;
	float mRotation;
	float mMass;

	std::vector<class Component*> mComponents;
};