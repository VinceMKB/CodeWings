#ifndef PILLARS_H
#define PILLARS_H

#include <iostream>
#include <map>
#include <deque>
#include <raylib.h>
using namespace std;

class Pillars
{
   
    public:
        map<int, deque<pair<Vector2, Vector2>>> pillars_map;
        float pillar_width;
        float pillar_height;

        Pillars();
        ~Pillars();

        void Update(float delta_time);
        void Draw();
        void AddPillar(int pillar_index,Vector2 top, Vector2 bottom);


};

#endif