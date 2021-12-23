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
	virtual ~Actor();

	void ProcessInput(const uint8_t* keystate);
	virtual void ActorInput(const uint8_t* keystate)
	{}

	void Update(float deltatime);
	void UpdateComponent(float deltatime);
	virtual void UpdateActor(float deltatime);

	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);

	class Game* GetGame() const { return mGame; }
	const Vector2& GetPosition() const { return mPosition; }
	float GetScale() const { return mScale; }
	State GetState() const { return mState; }

	void SetState(State state) { mState = state; }
	void SetScale(float scale) { mScale = scale; }
	void SetPosition(Vector2 pos) { mPosition = pos; }

	class GravityComponent* mActorGravity;
private:
	Game* mGame;
	Vector2 mPosition;
	float mScale;
	State mState;

	std::vector<class Component*> mComponents;
};