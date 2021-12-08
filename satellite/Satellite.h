#pragma once
#include "Actor.h"

class Satellite : public Actor
{
public:
	Satellite(class Game* game);

	void Update(float deltatime);//worldsizeはここで判定

private:
	Vector2 mFirstPos;

};