#include "physics.h"

void ApplyGravity(Sprite* character, float delta){
    character->Velocity.y += 100;
    if(character->Velocity.y > 1000){
        character->Velocity.y = 1000;
    }
}

// To Be Continued

void UpdatePlayer(Sprite* character, float delta, Platform* Items, int Length){
    character->Velocity.x = 0.0f;
    ApplyGravity(character, delta);
    if(IsKeyDown(KEY_D)){
        character->Velocity.x = 300;
        character->dir = RIGHT;
    }
    if(IsKeyDown(KEY_A)){
        character->Velocity.x = -300;
        character->dir = LEFT;
    }
    if(IsKeyPressed(KEY_SPACE) && character->CanJump){
        character->Velocity.y = -1000.0;
        character->CanJump = false;
    }

    bool hitObstacle = true;

    character->Destination.x += character->Velocity.x * delta;
    character->Destination.y += character->Velocity.y * delta;
            
    for(int i = 0; i < Length; i++){
        Platform* pItem = &Items[i];
        if (pItem->Blocking &&
            pItem->rectangle.x < character->Destination.x + character->Destination.width &&
            pItem->rectangle.x + pItem->rectangle.width > character->Destination.x &&
            pItem->rectangle.y < character->Destination.y + character->Destination.height &&
            pItem->rectangle.y + pItem->rectangle.height > character->Destination.y)
            {
                hitObstacle = true;
                character->Velocity.y = 0.0f;
                character->Destination.y = pItem->rectangle.y - character->Destination.height; 
                break;
            }

        if(!hitObstacle)
            character->CanJump = false;
        else
            character->CanJump = true;
    }
    
}

/* Im the goat  */


/* bool hitObstacle = false; */

/* for(int i = 0; i < Length; i++){ */
/*     Platform* pi = &Items[i]; */
/*     // To Be Continued */
/*     /\* float* px = &(character->Destination.x); *\/ */
/*     /\* float* py = &(character->Destination.y); *\/ */
/*     if (pi->Blocking && */
/*         pi->rectangle.x < character->Destination.x + character->Destination.width && */
/*         pi->rectangle.x + pi->rectangle.width > character->Destination.x && */
/*         pi->rectangle.y < character->Destination.y + character->Destination.height && */
/*         pi->rectangle.y + pi->rectangle.height > character->Destination.y) */
/*         { */
/*             hitObstacle = true; */
/*             character->Velocity.y = 0.0f; */
/*             character->Destination.y = pi->rectangle.y; */
/*             break; */
/*         } */
/* } */

/* if(!hitObstacle){ */
/*     character->Destination.y += character->Velocity.y * delta; */
/*     character->Velocity.y += 400; */
/*     character->CanJump = false; */
/* } */
/* else */
/*     character->CanJump = true; */


/* if(pItem->Blocking &&  */
/*          pItem->rectangle.x <= character->Destination.x  && */
/*          pItem->rectangle.x + pItem->rectangle.width >= character->Destination.x && */
/*          pItem->rectangle.y >= character->Destination.y && */
/*          pItem->rectangle.y <= character->Destination.y) */
/*           { */
/*               hitObstacle = true; */
/*               character->Velocity.y = 0.0f; */
/*               character->Destination.y = pItem->rectangle.y; */
/*               break; */
/*           } */
            
