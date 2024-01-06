#include "Components/MoveComponent.hpp"
#include "Actors/Actor.hpp"
#include "Components/Component.hpp"
#include "Helpers/Math.hpp"

MoveComponent::MoveComponent(class Actor* owner, int updateOrder)
    : Component(owner, updateOrder)
    , mAngularSpeed(0.0f)
    , mForwardSpeed(0.0f)
    , mMass(1.0f)
    , mForce(Vector2(0.0f, 0.0f))
    , mVelocity(Vector2(1.0f, 1.0f))
{
}

void MoveComponent::Update(float deltaTime)
{
    if (mOwner->GetMoveStatus())
    {

        if (!Math::NearZero(mAngularSpeed))
        {
            float rot = mOwner->GetRotation();
            rot += mAngularSpeed * deltaTime;
            mOwner->SetRotation(rot);
        }

        if (!Math::NearZero(mVelocity.Length()))
        {
            Vector2 pos = mOwner->GetPosition();
            Vector2 acceleration = Vector2(mForce.x / mMass, mForce.y / mMass);
            mVelocity += acceleration * deltaTime;

            pos += mVelocity * deltaTime;

            if (pos.x < 0.0f)
            {
                pos.x = 1022.0f;
            }
            else if (pos.x > 1024.0f)
            {
                pos.x = 2.0f;
            }

            if (pos.y < 0.0f)
            {
                pos.y = 766.0f;
            }
            else if (pos.y > 768.0f)
            {
                pos.y = 2.0f;
            }

            mOwner->SetPosition(pos);
        }
    }
    else
    {
        SetForce(Vector2(0.0f, 0.0f));
        SetVelocity(Vector2(0.1f, 0.1f));
    }
}
