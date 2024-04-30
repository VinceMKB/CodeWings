#include "game_logic.h"

GameLogic::GameLogic()
{
    paused_game = false;
    draw_first_map = true;
    draw_second_map = false;
    score = 0;
}

GameLogic::~GameLogic()
{

}

void GameLogic::Draw()
{
    
    background.Draw();
    //pillar.Draw_Initial_Map();
    if(draw_first_map == true)
    {
        pillar.Draw_FirstMap();
    }

    if(draw_second_map == true)
    {
        pillar.Draw_SecondMap();
    }
    bird.Draw();
    if(paused_game == true)
    {
        DrawText("GAME OVER", 300, 400, 50, RED);
    }
    
}

void GameLogic::Update(float delta_time)
{
    bird.Update(delta_time);
    //pillar.Update_Initial(delta_time);
    if(draw_first_map == true)
    {
        pillar.Update_FirstMap(delta_time);
    }
    if(draw_second_map == true)
    {
        pillar.Update_SecondMap(delta_time);
    }
    background.Update(delta_time);

    if(Check_Collision_With_Pillars(pillar.initial_pillars_map, pillar.pillar_width, pillar.pillar_height))
    {
        cout << "TOUCHED PILLAR!!" << endl;
        GameOver();
    }
    
    //First Map Pillars
    if(Check_Last_Pillar_Passed(pillar.second_pillars_map))
    {
        draw_first_map = true;
    }

    if(Check_Last_Pillar_Off_Screen(pillar.first_pillars_map))
    {
        pillar.first_pillars_map = pillar.RandomiseIndex(pillar.first_pillars_map);
        draw_first_map = false;
    }
    //End of First Map Pillars

    //Second Map Pillars
    if(Check_Last_Pillar_Passed(pillar.first_pillars_map))
    {
        draw_second_map = true;
    }

    if(Check_Last_Pillar_Off_Screen(pillar.second_pillars_map))
    {
        pillar.second_pillars_map = pillar.RandomiseIndex(pillar.second_pillars_map);
        draw_second_map = false;
    }
    //End Map Pillars
}

bool GameLogic::Check_Collision_With_Pillars(const map<int, deque<pair<Vector2, Vector2>>>& pillars_map, const float& pillar_width, const float& pillar_height)
{
    Rectangle playerBoundingBox = { bird.position.x, bird.position.y, (float)bird.current_texture.width, (float)bird.current_texture.height };

    for (const auto& pillar_pair : pillars_map) 
    {
        for (const auto& pillar : pillar_pair.second) 
        {
            Rectangle topPillar = { pillar.first.x, pillar.first.y, pillar_width, pillar_height };
            Rectangle bottomPillar = { pillar.second.x, pillar.second.y, pillar_width, pillar_height };

            if (CheckCollisionRecs(playerBoundingBox, topPillar) || CheckCollisionRecs(playerBoundingBox, bottomPillar)) 
            {
                return true; // Collision detected
            }
        }
    }
    return false; // No collision detected    
}

bool GameLogic::Check_Last_Pillar_Passed(const map<int, deque<pair<Vector2, Vector2>>>& pillars_map)
{
    
    // Check if the map is not empty
    if (!pillars_map.empty()) 
    {
        // Get the last index of the map
        auto lastIndex = pillars_map.rbegin()->first;

        // Check if there are pillars in the last index
        if (!pillars_map.at(lastIndex).empty()) 
        {
            // Get the last pillar in the last index
            auto lastPillar = pillars_map.at(lastIndex).back();

            // Check if the x position of the last pillar is less than 700
            if (lastPillar.first.x < 700) 
            {
                return true; // The last pillar has passed the position
            }
        }
    }
    return false; // The last pillar has not passed the position

}

bool GameLogic::Check_Last_Pillar_Off_Screen(const map<int, deque<pair<Vector2, Vector2>>>& pillars_map)
{
        // Check if the map is not empty
    if (!pillars_map.empty()) 
    {
        // Get the last index of the map
        auto lastIndex = pillars_map.rbegin()->first;

        // Check if there are pillars in the last index
        if (!pillars_map.at(lastIndex).empty()) 
        {
            // Get the last pillar in the last index
            auto lastPillar = pillars_map.at(lastIndex).back();

            // Check if the x position of the last pillar is less than 700
            if (lastPillar.first.x < 0) 
            {
                return true; // The last pillar has passed the position
            }
        }
    }
    return false; // The last pillar has not passed the position
}

void GameLogic::GameOver()
{
    paused_game = true;
}

void GameLogic::Reset()
{

    bird.position = {200, 200};
    bird.velocity = {0, 0};
    score = 0;

    pillar.Reset();

}