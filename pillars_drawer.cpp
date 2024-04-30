#include "pillars_drawer.h"

PillarsDrawer::PillarsDrawer() : pillar_width(50.0f), pillar_height(350.0f)
{
    
    AddPillar(1, {300.0f, 0.0f}, {300.0f, 500.0f});
    AddPillar(2, {450.0f, 25.0f}, {450.0f, 525.0f});
    AddPillar(3, {600.0f, 75.0f}, {600.0f, 575.0f});
    AddPillar(4, {750.0f, 100.0f}, {750.0f, 600.0f});
    AddPillar(5, {900.0f, 50.0f}, {900.0f, 550.0f});
    AddPillar(6, {1050.0f, 125.0f}, {1050.0f, 625.0f});

    Initialize_Maps(initial_pillars_map);
    
}

PillarsDrawer::~PillarsDrawer()
{
}

void PillarsDrawer::Initialize_Maps(map<int, deque<pair<Vector2, Vector2>>>& pillars_map)
{
    
    first_pillars_map = initial_pillars_map;

    for(const auto& pillar_pair : initial_pillars_map)
    {
        int pillarIndex = pillar_pair.first;
        for (const auto& pillar : pillar_pair.second) {
            // Adjust the x-position of the top and bottom points
            Vector2 adjustedTop = {pillar.first.x + 500.0f, pillar.first.y};
            Vector2 adjustedBottom = {pillar.second.x + 500.0f, pillar.second.y};
            // Add the adjusted pillar to second_pillars_map
            second_pillars_map[pillarIndex].push_back({adjustedTop, adjustedBottom});
        }
    }    
    
}

void PillarsDrawer::Update_FirstMap(float delta_time)
{
    
    //Move pillars to left
    for(auto& pillar_pair : first_pillars_map)
    {
        for(auto& pillar : pillar_pair.second)
        {
            pillar.first.x -= 15.0f * delta_time;
            pillar.second.x -= 15.0f * delta_time;
        }
    }

}

void PillarsDrawer::Draw_FirstMap()
{
    for(auto& pillar_pair : first_pillars_map)
    {
        for(const auto& pillar : pillar_pair.second)
        {
            DrawRectangle(pillar.first.x, pillar.first.y, pillar_width, pillar_height, BLACK);
            DrawRectangle(pillar.second.x, pillar.second.y, pillar_width, pillar_height, GREEN);
        }
    }    
}

void PillarsDrawer::Update_SecondMap(float delta_time)
{
    
    //Move pillars to left
    for(auto& pillar_pair : second_pillars_map)
    {
        for(auto& pillar : pillar_pair.second)
        {
            pillar.first.x -= 15.0f * delta_time;
            pillar.second.x -= 15.0f * delta_time;
        }
    }
    
}

void PillarsDrawer::Draw_SecondMap()
{
    for(auto& pillar_pair : second_pillars_map)
    {
        for(const auto& pillar : pillar_pair.second)
        {
            DrawRectangle(pillar.first.x, pillar.first.y, pillar_width, pillar_height, BLACK);
            DrawRectangle(pillar.second.x, pillar.second.y, pillar_width, pillar_height, GREEN);
        }
    }    
}

//Move to Manager
void PillarsDrawer::AddPillar(int pillar_index, Vector2 top, Vector2 bottom)
{
    initial_pillars_map[pillar_index].push_back({top, bottom});
}

void PillarsDrawer::Reset()
{
    //Clear the current pillar
    first_pillars_map.clear();
    second_pillars_map.clear();

    //Add the pillars to their initial positions
    *this = PillarsDrawer();
}
