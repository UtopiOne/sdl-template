#pragma once

#include <cstdint>
#include <vector>

#include "Helpers/Math.hpp"

class Actor
{
public:
    enum State
    {
        EActive,
        EPaused,
        EDead,
    };

    Actor(class Game* game);
    virtual ~Actor();

    void Update(float deltaTime);
    void UpdateComponents(float deltaTime);
    virtual void UpdateActor(float deltaTime);

    void ProcessInput(const uint8_t* keyState);
    virtual void ActorInput(const uint8_t* keyState);

    // Getters/setters

    // Position
    const Vector2& GetPosition() const { return mPosition; }
    void SetPosition(const Vector2& pos) { mPosition = pos; }
    // Scale
    float GetScale() const { return mScale; }
    void SetScale(float scale) { mScale = scale; }
    // Rotation
    float GetRotation() const { return mRotation; }
    void SetRotation(float rotation) { mRotation = rotation; }

    Vector2 GetForward() const { return Vector2(Math::Cos(mRotation), -Math::Sin(mRotation)); }
    // State
    State GetState() const { return mState; }
    void SetState(State state) { mState = state; }

    bool GetMoveStatus() const { return mCanMove; }
    void SetMoveStatus(bool canMove) { mCanMove = canMove; }

    class Game* GetGame() { return mGame; }

    void AddComponent(class Component* component);
    void RemoveComponent(class Component* component);

private:
    State mState;

    Vector2 mPosition;
    float mScale;
    float mRotation;

    bool mCanMove;

    std::vector<class Component*> mComponents;

    class Game* mGame;
};
