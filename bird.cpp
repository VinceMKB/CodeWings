#include "bird.h"

Bird::Bird()
{
    Image image_1 = LoadImage("Resources/Nerd_FlapUp.png");
    Image image_2 = LoadImage("Resources/Nerd_FlapDown.png");
    if (image_1.data == NULL && image_2.data == NULL) 
    {
        std::cerr << "Failed to load images" << std::endl;
        // Handle the error appropriately
    }
    current_texture = LoadTextureFromImage(image_1);
    nerd_up_texture = LoadTextureFromImage(image_1);
    nerd_down_texture = LoadTextureFromImage(image_2);
    UnloadImage(image_1);
    UnloadImage(image_2);
    position ={200, 200};//Position of Character
}

Bird::~Bird()
{
    UnloadTexture(current_texture);
    UnloadTexture(nerd_up_texture);
    UnloadTexture(nerd_down_texture);
}

void Bird::Draw()
{
    if (current_texture.id == 0) 
    {
        std::cerr << "Texture not loaded" << std::endl;
        return;
    }
    DrawTexture(current_texture, position.x, position.y, WHITE);

}

void Bird::Update(float delta_time)
{
    velocity.y += 98.0f * delta_time;

    position.x += velocity.x * delta_time;
    position.y += velocity.y * delta_time;

    if (velocity.y < 0) 
    {
        current_texture = nerd_down_texture; // Moving down
    } 
    else 
    {
        current_texture = nerd_up_texture; // Moving up or not moving vertically
    }

    if(position.x < 0)
    {
        position.x = 0;
    }
    if(position.y < 0)
    {
        position.y = 0;
    }
    if(position.x > (GetScreenWidth() - 75) - current_texture.width)
    {
        position.x =(GetScreenWidth() - 75) - current_texture.width;
    }
    if(position.y > (GetScreenHeight() - 75) - current_texture.height)
    {
        position.y = (GetScreenHeight() - 75) - current_texture.height;
    }

    if(IsKeyPressed(KEY_SPACE) && velocity.y >= -0.5)
    {
        velocity.y = -100.0f;
    }
}