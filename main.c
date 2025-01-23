#include <physics.h>

int main()
{
    const int ScreenWidth = 1280;
    const int ScreenHeight = 720;
    InitWindow(ScreenWidth, ScreenHeight, "Pepsi");

    Texture2D player_texture = LoadTexture("assets/idle.png");
    Rectangle player_dest = {350, 100, 100, 110};
    Sprite player = NewSprite(player_texture, player_dest);

    Platform Items[] = {
        {{300, 500, 800, 100}, 1, BROWN},
    };
    int ItemsLength = sizeof(Items) / sizeof(Items[0]);

    Camera2D camera = {0};
    camera.target = player.Position;
    camera.offset = (Vector2){ ScreenWidth / 2.0f, ScreenHeight / 2.0f };
    camera.rotation = 01.0f;
    camera.zoom = 1.0f;

    SetTargetFPS(60);

    while(!WindowShouldClose()){
        float DeltaTime = GetFrameTime();
        UpdatePlayer(&player, DeltaTime, Items, ItemsLength);
        // Set Physics for the platforms first
    
        BeginDrawing();
        ClearBackground(SKYBLUE);
        for(int i = 0; i < ItemsLength; i++){
            DrawRectangleRec(Items[i].rectangle, Items[i].color);
        }

        DrawRectangleRec((Rectangle){350, 400, 100, 100}, GREEN);
        /* if(player.Destination.y > ScreenHeight - player.Destination.height){ */
        /*     player.Destination.y = ScreenHeight - player.Destination.height; */
        /* } */

        
        DrawTexturePro(player.Texture, (Rectangle){34, 30, 14 * player.dir, 17},
                       player.Destination, (Vector2){0, 0}, 0.0f, RAYWHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

