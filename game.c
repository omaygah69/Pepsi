#include "blyat.h"

void Animate(Sprite* sprite, float delta)
{
  
}

Sprite NewSprite(Texture2D Texture, Rectangle Destination)
{
    Sprite sprite = (Sprite){
        .Texture = Texture,
        .CanJump = true,
        .Destination = Destination,
        .Position = (Vector2){ Destination.x, Destination.y },
        .dir = RIGHT,
    };

   return sprite;
}


