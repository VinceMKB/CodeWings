#include "Pillars.h"

Pillars::Pillars() : pillar_width(50.0f), pillar_height(350.0f)
{
    AddPillar(1, {500.0f, 100.0f}, {500.0f, 600.0f});
    AddPillar(2, {600.0f, 150.0f}, {600.0f, 650.0f});
    AddPillar(3, {700.0f, 200.0f}, {700.0f, 700.0f});
}

Pillars::~Pillars()
{
}

void Pillars::Update(float delta_time)
{
    // Move pillars to the left
    for(auto& pillar_pair : pillars_map)
    {
        for(auto& pillar : pillar_pair.second)
        {
            pillar.first.x -= 15.0f * delta_time;
            pillar.second.x -= 15.0f * delta_time;
        }
    }
    
    // Removes Pillars
    for(auto& pillar_pair : pillars_map)
    {
        while(!pillar_pair.second.empty() && pillar_pair.second.front().first.x < 0)
        {
            pillar_pair.second.pop_front();
        }
    }
}

void Pillars::Draw()
{
    for(auto& pillar_pair : pillars_map)
    {
        for(const auto& pillar : pillar_pair.second)
        {
            DrawRectangle(pillar.first.x, pillar.first.y, pillar_width, pillar_height, BLACK);
            DrawRectangle(pillar.second.x, pillar.second.y, pillar_width, pillar_height, GREEN);
        }
    }
}

void Pillars::AddPillar(int pillar_index, Vector2 top, Vector2 bottom)
{
    pillars_map[pillar_index].push_back({top, bottom});
}
