#pragma once

#include <SDL2/SDL.h>

#include <vector>
#include <string>

#include "Helpers/CSVParser.hpp"
#include "Actors/Actor.hpp"
#include "SpriteComponent.hpp"

class TileMapComponent : public SpriteComponent
{
public:
    TileMapComponent(class Actor* owner, int drawOrder = 100);
    ~TileMapComponent();

    void Update(float deltaTime) override;
    void Draw(SDL_Renderer* renderer) override;

    void SetTileMap(const std::string path) { mTileMap = ParseCsv(path); }
    void SetTileSet(SDL_Texture* tileSet) { mTileSet = tileSet; }

    void SetTileSetWidth(const int width) { mTileSetWidth = width; }
    int GetTileSetWidth() { return mTileSetWidth; }
    void SetTileSetHeight(const int height) { mTileSetWidth = height; }
    int GetTileSetHeight() { return mTileSetHeight; }

    void SetTileWidth(const int width) { mTileWidth = width; }
    int GetTileWidth() { return mTileSetWidth; }
    void SetTileHeight(const int height) { mTileHeight = height; }
    int GetTileHeight() { return mTileHeight; }

private:
    std::vector<std::vector<int>> mTileMap;

    int mTileSetWidth;
    int mTileSetHeight;

    int mTileWidth;
    int mTileHeight;

    SDL_Texture* mTileSet;
};
