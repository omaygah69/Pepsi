#include "physics.h"

void ApplyGravity(Sprite* character, float delta){
    character->Velocity.y += 100;
    if(character->Velocity.y > 1000){
        character->Velocity.y = 1000;
    }
    character->Destination.x += character->Velocity.x * delta;
    character->Destination.y += character->Velocity.y * delta;
}

void UpdatePlayer(Sprite* character, float delta){
    character->Velocity.x = 0.0f;
    if(IsKeyDown(KEY_D)){
        character->Velocity.x = 200;
        character->Destination.x += character->Velocity.x * delta;
        character->dir = RIGHT;
    }
    if(IsKeyDown(KEY_A)){
        character->Velocity.x = -200;
        character->Destination.x += character->Velocity.x * delta;
        character->dir = LEFT;
    }
    if(IsKeyPressed(KEY_SPACE)){
        character->Velocity.y = -1000.0;
    }

}
/* Im the goat  */
