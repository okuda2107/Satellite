#pragma once
#include <cstdint>

class Component
{
public:
	Component(class Actor* owner, int updateOrder = 100);
	virtual ~Component();

	virtual void ProcessInput(const uint8_t* keystate)
	{}

	virtual void Update(float deltatime);

	virtual void OnUpdateWorldTransform() { }

	const int GetUpdateOrder() { return mUpdateOrder; }

	class Actor* GetOwner() { return mOwner; }
protected:
	class Actor* mOwner;
	int mUpdateOrder;
};