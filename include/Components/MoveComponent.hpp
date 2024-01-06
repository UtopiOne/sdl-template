#pragma once

#include "Components/Component.hpp"
#include "Helpers/Math.hpp"

class MoveComponent : public Component
{
public:
    MoveComponent(class Actor* owner, int updateOrder = 100);

    void Update(float deltaTime) override;

    float GetAngularSpeed() const { return mAngularSpeed; }
    float GetForwardSpeed() const { return mForwardSpeed; }
    float GetMass() const { return mMass; }
    Vector2 GetForce() const { return mForce; }
    Vector2 GetVelocity() const { return mVelocity; }

    void SetAngularSpeed(float speed) { mAngularSpeed = speed; }
    void SetForwardSpeed(float speed) { mForwardSpeed = speed; }
    void SetMass(float mass) { mMass = mass; }
    void SetVelocity(Vector2 velocity) { mVelocity = velocity; }
    void SetForce(Vector2 force) { mForce = force; }

private:
    float mAngularSpeed;
    float mForwardSpeed;
    float mMass;

    Vector2 mForce;
    Vector2 mVelocity;
};
