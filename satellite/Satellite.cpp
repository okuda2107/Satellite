#include "Satellite.h"
#include "Actor.h"
#include "InputComponent.h"
#include "SDL.h"
#include "SpriteComponent.h"
#include "Game.h"

Satellite::Satellite(class Game* game) : Actor(game)
{
	InputComponent* inpc = new InputComponent(this);
	inpc->SetTag(inpc->Player);
	inpc->SetMass(10.0f);
	inpc->SetSpeed(35.0f);
	inpc->SetAcceleKey(SDL_SCANCODE_W);
	inpc->SetDeceleKey(SDL_SCANCODE_S);
	inpc->SetAccele(1.0f);
	SpriteComponent* sc = new SpriteComponent(this, 100);
	sc->SetTexture(GetGame()->GetTexture("Assets/face.png"));
}