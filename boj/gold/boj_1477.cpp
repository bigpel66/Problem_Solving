#include <iostream>
#include <vector>
#include <algorithm>

int                                                             g_number_of_original;
int                                                             g_number_of_newly;
int                                                             g_highway_dist;
int                                                             g_answer;
std::vector<int>                                                g_rest_area_pos;

void                                                            pre_setting(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}

void                                                            input_action(void)
{
    int                                                         index;

    std::cin >> g_number_of_original >> g_number_of_newly >> g_highway_dist;
    g_rest_area_pos = std::vector<int>(g_number_of_original + 2, 0);
    g_rest_area_pos[0] = 0;
    g_rest_area_pos[g_number_of_original + 1] = g_highway_dist;
    index = 0;
    while (++index < g_number_of_original + 1)
        std::cin >> g_rest_area_pos[index];
    std::sort(g_rest_area_pos.begin(), g_rest_area_pos.end());
    g_answer = -1;
    index = -1;
    while (++index < g_number_of_original + 1)
        g_answer = std::max(g_answer, g_rest_area_pos[index + 1] - g_rest_area_pos[index]);
}

bool                                                            decrease_dist(int dist)
{
    int                                                         index;
    int                                                         count;
    int                                                         diff;

    index = -1;
    count = 0;
    while (++index < g_number_of_original + 1)
    {
        diff = g_rest_area_pos[index + 1] - g_rest_area_pos[index];
        count += (diff - 1) / dist;
    }
    return (count <= g_number_of_newly);
}

void                                                            binary_search(void)
{
    int                                                         start;
    int                                                         end;
    int                                                         mid;

    start = 1;
    end = g_answer;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (decrease_dist(mid))
        {
            g_answer = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
}

void                                                            output_action(void)
{
    std::cout << g_answer;
}

void                                                            solution(void)
{
    input_action();
    binary_search();
    output_action();
}

int                                                             main(void)
{
    pre_setting();
    solution();
    return (0);
}
