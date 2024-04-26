#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <raylib.h>
#include <iostream>
using namespace std;

class BackGround
{
    public:
        Texture2D background_texture;
        float background_speed;
        Vector2 background_position_one;
        Vector2 background_position_two;

        BackGround();
        ~BackGround();

        void Draw();
        void Update(float delta_time);

};
#endif