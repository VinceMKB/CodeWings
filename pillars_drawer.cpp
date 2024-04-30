#include "pillars_drawer.h"

PillarsDrawer::PillarsDrawer() : pillar_width(50.0f), pillar_height(350.0f)
{
    AddPillar(1, {300.0f, 0.0f}, {300.0f, 500.0f});
    AddPillar(2, {450.0f, 25.0f}, {450.0f, 525.0f});
    AddPillar(3, {600.0f, 75.0f}, {600.0f, 575.0f});
    AddPillar(4, {750.0f, 100.0f}, {750.0f, 600.0f});
    AddPillar(5, {900.0f, 50.0f}, {900.0f, 550.0f});
    AddPillar(6, {1050.0f, 125.0f}, {1050.0f, 625.0f});

    first_pillars_map = initial_pillars_map;
    second_pillars_map = initial_pillars_map;
    
}

PillarsDrawer::~PillarsDrawer()
{
}
/*
void PillarsDrawer::Update_Initial(float delta_time)
{
    // Move pillars to the left
    for(auto& pillar_pair : initial_pillars_map)
    {
        for(auto& pillar : pillar_pair.second)
        {
            pillar.first.x -= 15.0f * delta_time;
            pillar.second.x -= 15.0f * delta_time;
        }
    }
    
    // Removes Pillars
    for(auto& pillar_pair : initial_pillars_map)
    {
        while(!pillar_pair.second.empty() && pillar_pair.second.front().first.x < 0)
        {
            pillar_pair.second.pop_front();
        }
    }

}
*/
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

    //Remove pillars
    for(auto& pillar_pair : first_pillars_map)
    {
        while(!pillar_pair.second.empty() && pillar_pair.second.front().first.x < 0)
        {
            pillar_pair.second.pop_front();
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

    //Remove pillars
    for(auto& pillar_pair : second_pillars_map)
    {
        while(!pillar_pair.second.empty() && pillar_pair.second.front().first.x < 0)
        {
            pillar_pair.second.pop_front();
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

/*
void PillarsDrawer::Draw_Initial_Map()
{
    for(auto& pillar_pair : initial_pillars_map)
    {
        for(const auto& pillar : pillar_pair.second)
        {
            DrawRectangle(pillar.first.x, pillar.first.y, pillar_width, pillar_height, BLACK);
            DrawRectangle(pillar.second.x, pillar.second.y, pillar_width, pillar_height, GREEN);
        }
    }
}
*/

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

/*
void PillarsDrawer::Reset()
{
    
    // Clear the current pillars
    initial_pillars_map.clear();

    // Add the pillars back to their initial positions
    *this = PillarsDrawer();

}
*/
/*
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
*/