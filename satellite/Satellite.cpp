#include "Satellite.h"
#include "Actor.h"
#include "SDL.h"
#include "SpriteComponent.h"
#include "Game.h"
#include "CircleComponent.h"
#include "Texture.h"
#include "Renderer.h"

Satellite::Satellite(class Game* game) : Actor(game)
{
	//aiueo
	GravityComponent* inpc = new GravityComponent(this);
	inpc->SetTag(inpc->Satellite);
	inpc->SetMass(1.0f);
	inpc->SetSpeed(Vector2(160.0f, 0.0f));
	SetScale(0.1f);
	SpriteComponent* sc = new SpriteComponent(this, 100);
	Texture* tex = GetGame()->GetRenderer()->GetTexture("Assets/face.png");
	sc->SetTexture(tex);
	SetPosition(Vector2(0.0f, -240.0f));
	SetScale(0.2f);
}

Satellite::~Satellite()
{
	
}