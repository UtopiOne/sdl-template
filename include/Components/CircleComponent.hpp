#pragma once

#include "Actors/Actor.hpp"
#include "Components/Component.hpp"
#include "Helpers/Math.hpp"

class CircleComponent : public Component
{
public:
    CircleComponent(class Actor* owner);

    void SetRadius(float radius) { mRadius = radius; }
    float GetRadius() const;

    const Vector2& GetCenter() const;

private:
    float mRadius;
};

bool Intersect(const CircleComponent& a, const CircleComponent& b);
