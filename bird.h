#ifndef BIRD_H
#define BIRD_H

#include <iostream>
#include "raylib.h"
using namespace std;

class Bird
{
    private:
        

    public:
        Vector2 position;
        Vector2 velocity;
        Texture2D current_texture;
        Texture2D nerd_up_texture;
        Texture2D nerd_down_texture;
        
        Bird();
        ~Bird();
        void Draw();
        void Update(float delta_time);

};

#endif