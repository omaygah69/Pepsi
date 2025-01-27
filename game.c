#include "blyat.h"

void UpdateCameraFollow(Camera2D* camera, Sprite* Character){
    static float minSpeed = 30;
    static float minLength = 10;
    static float fractionSpeed = 0.8;
}

void UpdateCameraFocusPlayer(Camera2D* camera, Sprite* character, int width, int height){
    camera->offset = (Vector2){ width / 2.0f, height / 2.0f };
    camera->target = (Vector2){ character->Destination.x, character->Destination.y };
}

void Animate(Sprite* sprite, float delta)
{
  
}

Sprite NewSprite(Texture2D Texture, Rectangle Destination)
{
    Sprite sprite = (Sprite){
        .Texture = Texture,
        .CanJump = false,
        .Destination = Destination,
        .Position = (Vector2){ Destination.x, Destination.y },
        .dir = RIGHT,
    };

   return sprite;
}


