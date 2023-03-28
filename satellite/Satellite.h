#pragma once
#include "Actor.h"

class Satellite : public Actor
{
public:
	Satellite(class Game* game);

	void UpdateActor(float deltatime) override;

private:
	class CircleComponent* mColider;
};