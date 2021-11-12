#include "InputComponent.h"

InputComponent::InputComponent(class Actor* owner) : GravityComponent(owner)
{}

void InputComponent::ProcessInput(const uint8_t* keystate)
{
	if (keystate[mAcceleKey])
	{
		UpdateSpeed(mAccele);
	}
}