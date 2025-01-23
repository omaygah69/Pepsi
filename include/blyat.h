#pragma once
#include <raylib.h>

typedef enum {
    RIGHT = 1,
    LEFT = -1,
} Direction;

typedef struct Sprite
{
    Vector2 Position;
    Texture2D Texture;
    bool CanJump;
    Rectangle Destination;
    Vector2 Velocity;
    Direction dir;
} Sprite;

typedef struct Platform
{
    Rectangle rectangle;
    int Blocking;
    Color color;
} Platform;

Sprite NewSprite(Texture2D Texture,
                  Rectangle Destination);

