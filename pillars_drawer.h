#ifndef PILLARS_H
#define PILLARS_H

#include <iostream>
#include <map>
#include <deque>
#include <raylib.h>
#include <random> // For random number generation
#include <algorithm>
#include <chrono>
using namespace std;

class PillarsDrawer
{
   
    public:
        map<int, deque<pair<Vector2, Vector2>>> initial_pillars_map;
        map<int, deque<pair<Vector2, Vector2>>> first_pillars_map;
        map<int, deque<pair<Vector2, Vector2>>> second_pillars_map;

        float pillar_width;
        float pillar_height;

        PillarsDrawer();
        ~PillarsDrawer();

        void Initialize_Maps(map<int, deque<pair<Vector2, Vector2>>>& pillars_map);

        //void Update_Initial(float delta_time);
        void Update_FirstMap(float delta_time);
        void Update_SecondMap(float delta_time);

        //void Draw_Initial_Map();
        void Draw_FirstMap();
        void Draw_SecondMap();

        map<int, deque<pair<Vector2, Vector2>>>RandomiseIndex(map<int, deque<pair<Vector2, Vector2>>>& pillars_map)
        {
            //Create a vector for indices
            vector <int> indices;
            for(const auto& pair : pillars_map)
            {
                indices.push_back(pair.first);
            }

            unsigned seed = chrono::system_clock::now().time_since_epoch().count();
            default_random_engine generator(seed);
            shuffle(indices.begin(), indices.end(), generator);

            map<int, deque<pair<Vector2, Vector2>>> shuffled_pillars_map;
            int new_index = 1;

            vector<deque<pair<Vector2, Vector2>>> grouped_pillars;
            for(int index : indices)
            {
                deque<pair<Vector2, Vector2>> pillars = pillars_map[index];
                grouped_pillars.push_back(pillars);
            }

            shuffle(grouped_pillars.begin(), grouped_pillars.end(), generator);

            float starting_point = 800.0f;
            for(auto& pillars : grouped_pillars)
            {
                for(auto& pillar : pillars)
                {
                    pillar.first.x = starting_point;
                    pillar.second.x = starting_point;
                    starting_point += 150;
                }
                shuffled_pillars_map[new_index] = pillars;
                new_index++;
            }

            return shuffled_pillars_map;

        }

        void AddPillar(int pillar_index,Vector2 top, Vector2 bottom);
        void Reset();

};

#endif