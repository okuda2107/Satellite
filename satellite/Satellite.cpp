#include "Satellite.h"
#include "Actor.h"
#include "InputComponent.h"
#include "SDL.h"
#include "SpriteComponent.h"
#include "Game.h"
#include "CircleComponent.h"
#include "StartActor.h"

Satellite::Satellite(class Game* game) : Actor(game)
{
	InputComponent* inpc = new InputComponent(this);
	inpc->SetTag(inpc->Player);
	inpc->SetMass(1.0f);
	inpc->SetSpeed(100.0f);
	inpc->SetAcceleKey(SDL_SCANCODE_W);
	inpc->SetDeceleKey(SDL_SCANCODE_S);
	inpc->SetAccele(1.0f);
	SetScale(0.1f);
	inpc->SetForward();
	SpriteComponent* sc = new SpriteComponent(this, 100);
	SDL_Texture* tex = GetGame()->GetTexture("Assets/face.png");
	sc->SetTexture(tex);
	CircleComponent* cc = new CircleComponent(this);
	cc->SetRadius(tex, GetScale());
}

Satellite::~Satellite()
{
	StartActor* sa = new StartActor(GetGame());
}