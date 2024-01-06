#pragma once

#include "SpriteComponent.hpp"

#include <string>
#include <vector>

struct Animation
{
    std::string Name;
    std::vector<SDL_Texture*> AnimTextures;
    float AnimFPS;

    bool Looping;
    bool HasEnded;
};

class AnimSpriteComponent : public SpriteComponent
{
public:
    AnimSpriteComponent(class Actor* owner, int drawOrder = 100);

    void Update(float deltaTime) override;

    void AttachAnimation(Animation animation);

    void SetCurrentAnimation(const std::string name);
    Animation GetCurrentAnimation() { return mCurrentAnimation; }

    float GetCurrentFrame() { return mCurrFrame; }

    float GetCurrentAnimFPS() const { return mCurrentAnimation.AnimFPS; }
    void SetCurrentAnimFPS(float fps) { mCurrentAnimation.AnimFPS = fps; }

private:
    std::vector<Animation> mAnimations;
    Animation mCurrentAnimation;
    float mCurrFrame;
};
