#include <iostream>
#include <raylib.h>

#include "game_logic.h"
using namespace std;



double last_update_time = 0;
bool event_triggered(double interval)
{
    double current_time = GetTime();
    if(current_time - last_update_time >= interval)
    {
        last_update_time = current_time;
        return true;
    }
    return false;
}

int main ()
{

    int CellSize = 32; // 800 by 800 with a border of 75
    int CellCount = 25;
    int Offset = 75;
   

    cout << "Hello World" << endl;

    InitWindow(2 * Offset + CellSize * CellCount, 2 * Offset + CellSize * CellCount, "FlappyBird");
    SetTargetFPS(60);
    Image background_image = LoadImage("Resources/BackGround.png");
    Texture2D background_texture = LoadTextureFromImage(background_image);
    UnloadImage(background_image);
  

    // Check if window initialization was successful
    if (!IsWindowReady())
    {
        cout << "Error initializing window" << endl;
        return 1;
    }
    GameLogic game = GameLogic();

    while (!WindowShouldClose())
    {
        
        float delta_time = GetFrameTime();
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(background_texture, 75, 75, WHITE);
        game.Update(delta_time);
        game.Draw();
        DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
