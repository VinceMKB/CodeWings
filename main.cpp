#include <iostream>
#include <raylib.h>

#include "game_logic.h"
using namespace std;

int main ()
{

    int CellSize = 32; // 800 by 800 with a border of 75
    int CellCount = 25;
   

    cout << "Hello World" << endl;
    InitWindow(CellSize * CellCount, CellSize * CellCount, "FlappyBird");
    SetTargetFPS(60);

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
        game.Update(delta_time);

        if(IsKeyPressed(KEY_SPACE) && game.paused_game)
        {
            game.Reset();
            game.paused_game = false;
        }

        game.Draw();
        DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
