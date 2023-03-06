#pragma once
#include "Actor.h"

class Planet : public Actor
{
public:
	Planet(class Game* game);
	~Planet();

	void SetFlag(bool flag) { mTargetFrag = flag; }
private:
	bool mTargetFrag;//�^�[�Q�b�g�t���O
};