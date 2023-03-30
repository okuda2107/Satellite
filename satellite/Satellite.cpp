#include "Satellite.h"
#include "Actor.h"
#include "SDL.h"
#include "SpriteComponent.h"
#include "Mesh.h"
#include "MeshComponent.h"
#include "Game.h"
#include "CircleComponent.h"
#include "Planet.h"
#include "Texture.h"
#include "Renderer.h"
#include <typeinfo>

Satellite::Satellite(class Game* game) : Actor(game)
{
	//aiueo
	GravityComponent* inpc = new GravityComponent(this);
	inpc->SetTag(inpc->Satellite);
	inpc->SetMass(1.0f);
	inpc->SetSpeed(Vector2(100.0f, .0f));
	MeshComponent* mc = new MeshComponent(this);
	mc->SetMesh(GetGame()->GetRenderer()->GetMesh("Assets/Sphere.gpmesh"));
	SetPosition(Vector2(0.0f, 240.0f));
	SetScale(3.0f);
	mColider = new CircleComponent(this);
	mColider->SetRadius(100.0f);
}

void Satellite::UpdateActor(float deltatime)
{
	if (!mColider->GetFlag()) return;
	Planet planet = Planet(GetGame());
	for (auto actor : mColider->mActors)
	{	
		if (typeid(*actor->GetOwner()) == typeid(planet))
		{
			this->SetState(EDead);
		}
	}
}
