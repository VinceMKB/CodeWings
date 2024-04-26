#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "bird.h"
#include "pillars.h"
#include "background.h"

class GameLogic
{
    public:
        Bird bird = Bird();
        Pillars pillar = Pillars();
        BackGround background = BackGround();
        
        bool running = true;
        int score = 0;

        void Draw();
        void Update(float delta_time);
        bool Check_Collision_With_Pillars(const map<int, deque<pair<Vector2, Vector2>>>& pillars_map, const float& pillar_width, const float& pillar_height);
        void GameOver();

};

#endif