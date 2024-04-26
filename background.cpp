#include "background.h"

BackGround::BackGround()
{
    background_speed = 15.0f;
    Image background_image = LoadImage("Resources/BackGround.png");
    background_texture = LoadTextureFromImage(background_image);
    UnloadImage(background_image);
    background_position_one =  {75, 75};
    background_position_two = {(float)background_texture.width + 75, 75};

}

BackGround::~BackGround()
{
    UnloadTexture(background_texture);
}

void BackGround::Update(float delta_time)
{
    background_position_one.x -= background_speed * delta_time;
    background_position_two.x -= background_speed * delta_time;

    //If the first background has moved off the screen, reset its position
    if(background_position_one.x <= -background_texture.width)
    {
        background_position_one.x = background_position_two.x + background_texture.width;
    }

    //If the second background has moved off the screen, reset its position
    if(background_position_two.x <= -background_texture.width)
    {
        background_position_two.x = background_position_one.x + background_texture.width;
    }
}

void BackGround::Draw()
{
    DrawTexture(background_texture, background_position_one.x, background_position_one.y, WHITE);
    DrawTexture(background_texture, background_position_two.x, background_position_two.y, WHITE);
}