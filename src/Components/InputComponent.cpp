#include "Components/InputComponent.hpp"
#include "Components/MoveComponent.hpp"
#include "Actors/Actor.hpp"
#include <cstdint>

InputComponent::InputComponent(class Actor* owner)
    : MoveComponent(owner)
    , mForwardKey(0)
    , mBackKey(0)
    , mClockwiseKey(0)
    , mCounterClockwiseKey(0)
{
}

void InputComponent::ProcessInput(const uint8_t* keyState)
{
    float forwardForce = 0.0f;
    if (keyState[mForwardKey])
    {
        forwardForce += mMaxForwardForce;
    }
    if (keyState[mBackKey])
    {
        forwardForce -= mMaxForwardForce;
    }
    SetForce(mOwner->GetForward() * forwardForce);

    float angularSpeed = 0.0f;
    if (keyState[mClockwiseKey])
    {
        angularSpeed += mMaxAngularSpeed;
    }
    if (keyState[mCounterClockwiseKey])
    {
        angularSpeed -= mMaxAngularSpeed;
    }

    SetAngularSpeed(angularSpeed);
}
