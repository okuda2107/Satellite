#pragma once
#include "Component.h"
#include "Math.h"
class MoveComponent :
    public Component
{
public:
    MoveComponent(class Actor* owner, int updateOrder = 10);
    void Update(float deltatime) override;

    Vector2& GetSpeed() { return mSpeed; }
    void SetSpeed(Vector2 speed) { mSpeed = speed; }

private:
    Vector2 mSpeed;
};
