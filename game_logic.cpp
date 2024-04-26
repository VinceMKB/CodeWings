#include "game_logic.h"

void GameLogic::Draw()
{
    bird.Draw();
    pillar.Draw();
}

void GameLogic::Update(float delta_time)
{
    bird.Update(delta_time);
    pillar.Update(delta_time);
    if(Check_Collision_With_Pillars(pillar.pillars_map, pillar.pillar_width, pillar.pillar_height))
    {
        cout << "TOUCHED PILLAR!!" << endl;
    }
}

bool GameLogic::Check_Collision_With_Pillars(const map<int, deque<pair<Vector2, Vector2>>>& pillars_map, const float& pillar_width, const float& pillar_height)
{
    Rectangle playerBoundingBox = { bird.position.x, bird.position.y, (float)bird.current_texture.width, (float)bird.current_texture.height };

    for (const auto& pillar_pair : pillars_map) {
        for (const auto& pillar : pillar_pair.second) {
            Rectangle topPillar = { pillar.first.x, pillar.first.y, pillar_width, pillar_height };
            Rectangle bottomPillar = { pillar.second.x, pillar.second.y, pillar_width, pillar_height };

            if (CheckCollisionRecs(playerBoundingBox, topPillar) || CheckCollisionRecs(playerBoundingBox, bottomPillar)) {
                return true; // Collision detected
            }
        }
    }
    return false; // No collision detected    
}

void GameLogic::GameOver()
{

}