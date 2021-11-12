#pragma once
#include "GravityComponent.h"
#include <cstdint>

class InputComponent : public GravityComponent
{
public:
	InputComponent(class Actor* owner);
	void ProcessInput(const uint8_t* keystate);

private:
	float mAccele;

	int mAcceleKey;
	int mDeceleKey;
};