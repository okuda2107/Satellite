#pragma once
#include "Actor.h"

class Satellite : public Actor
{
public:
	Satellite(class Game* game);

	void ActorInput(const uint8_t* keystate);

	void UpdateActor(float deltatime);

private:
//Õ“ËŒŸ’m
	class CircleComponent* mCircle;

};