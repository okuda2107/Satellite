#pragma once
#include "GravityComponent.h"
#include <cstdint>

class InputComponent : public GravityComponent
{
public:
	InputComponent(class Actor* owner);
	void ProcessInput(const uint8_t* keystate);

	void SetAcceleKey(int state) { mAcceleKey = state; }
	void SetDeceleKey(int state) { mDeceleKey = state; }
	void SetAccele(float accele) { mAccele = accele; }
private:
	float mAccele;

	int mAcceleKey;
	int mDeceleKey;
};