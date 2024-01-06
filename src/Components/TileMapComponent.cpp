#include "Components/TileMapComponent.hpp"
#include "Helpers/Math.hpp"
#include "Components/SpriteComponent.hpp"

#include <cmath>

TileMapComponent::TileMapComponent(class Actor* owner, int drawOrder)
    : SpriteComponent(owner, drawOrder)
{
}

TileMapComponent::~TileMapComponent()
{
}

void TileMapComponent::Update(float deltaTime)
{
    SpriteComponent::Update(deltaTime);
}

void TileMapComponent::Draw(SDL_Renderer* renderer)
{
    int rowCount = 0;

    for (auto row : mTileMap)
    {
        int colCount = 0;

        for (auto tile : row)
        {
            SDL_Rect resRect;

            resRect.w = static_cast<int>(mOwner->GetScale());
            resRect.h = static_cast<int>(mOwner->GetScale());
            resRect.x = static_cast<int>(mOwner->GetPosition().x - resRect.w / 2) + colCount * resRect.w;
            resRect.y = static_cast<int>(mOwner->GetPosition().y - resRect.h / 2) + rowCount * resRect.h;

            SDL_Rect srcRect;

            srcRect.w = 32;
            srcRect.h = 32;

            if (tile == -1)
            {
                srcRect.x = 0;
                srcRect.y = 0;
            }
            else
            {
                srcRect.x = (tile % 8) * mTileWidth;
                srcRect.y = floor(tile / 8) * mTileHeight;
            }

            SDL_RenderCopyEx(renderer, mTileSet, &srcRect, &resRect, -Math::ToDegrees(mOwner->GetRotation()), nullptr, SDL_FLIP_NONE);

            colCount += 1;
        }

        rowCount += 1;
    }
}
