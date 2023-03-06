#pragma once
#include "Actor.h"

class Satellite : public Actor
{
public:
	Satellite(class Game* game);
	~Satellite();

	void Update(float deltatime);//worldsize�͂����Ŕ���

private:
	Vector2 mFirstPos;

};