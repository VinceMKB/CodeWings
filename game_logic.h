#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "bird.h"
#include "pillars_drawer.h"
#include "background.h"

class GameLogic
{
    public:
        Bird bird = Bird();
        PillarsDrawer pillar = PillarsDrawer();
        BackGround background = BackGround();

        GameLogic();
        ~GameLogic();
        
        bool paused_game;
        bool draw_first_map;
        bool draw_second_map;
        int score;

        void Draw();
        void Update(float delta_time);

        bool Check_Collision_With_Pillars(const map<int, deque<pair<Vector2, Vector2>>>& pillars_map, const float& pillar_width, const float& pillar_height);

        bool Check_Last_Pillar_Passed(const map<int, deque<pair<Vector2, Vector2>>>& pillars_map);
        bool Check_Last_Pillar_Off_Screen(const map<int, deque<pair<Vector2, Vector2>>>& pillars_map);

        void GameOver();
        void Reset();

};

#endif