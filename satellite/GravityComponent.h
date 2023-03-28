#pragma once
#include "MoveComponent.h"
#include "Math.h"

class GravityComponent :
    public MoveComponent
{
public:
    enum Tag
    {
        Satellite,
        Planet
    };
    GravityComponent(class Actor* owner, int updateOrder = 10);
    ~GravityComponent();

    void Update(float deltatime);

    void SetTag(Tag tag) { mTag = tag; }
    void SetMass(float mass) { mMass = mass; }

private:
    Vector2 culculateGravity(float deltatime);

    Tag mTag;
    float mMass;

    static constexpr float gravity = 980665.f;
};

