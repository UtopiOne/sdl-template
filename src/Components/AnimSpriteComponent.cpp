#include "Components/AnimSpriteComponent.hpp"
#include "Actors/Actor.hpp"
#include "SDL_render.h"
#include "Components/SpriteComponent.hpp"

AnimSpriteComponent::AnimSpriteComponent(Actor* owner, int drawOrder)
    : SpriteComponent(owner, drawOrder)
    , mCurrFrame(0.0f)
{
}

void AnimSpriteComponent::Update(float deltaTime)
{
    SpriteComponent::Update(deltaTime);

    if (mCurrentAnimation.AnimTextures.size() > 0)
    {
        mCurrFrame += mCurrentAnimation.AnimFPS * deltaTime;

        while (mCurrFrame >= mCurrentAnimation.AnimTextures.size())
        {
            if (mCurrentAnimation.Looping)
            {
                mCurrFrame -= mCurrentAnimation.AnimTextures.size();
            }
            else
            {
                mCurrFrame = mCurrentAnimation.AnimTextures.size() - 1;
                mCurrentAnimation.HasEnded = true;
            }
        }

        SetTexture(mCurrentAnimation.AnimTextures[static_cast<int>(mCurrFrame)]);
    }
}

void AnimSpriteComponent::SetCurrentAnimation(const std::string name)
{
    for (auto anim : mAnimations)
    {
        if (anim.Name == name && mCurrentAnimation.Name != name)
        {
            mCurrFrame = 0.0f;
            mCurrentAnimation = anim;
        }
    }
}

void AnimSpriteComponent::AttachAnimation(Animation animation)
{
    mAnimations.push_back(animation);
}
