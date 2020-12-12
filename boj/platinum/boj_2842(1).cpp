#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int                                                             g_row_size;
int                                                             g_matrix_size;
int                                                             g_result;
std::string                                                     g_map;
std::vector<int>                                                g_alt;
std::vector<int>                                                g_unique_alt;
std::pair<int, int>                                             g_post_office;
std::vector<std::pair<int, int> >                               g_houses;
std::vector<std::pair<int, int> >                               g_displacement;
std::vector<bool>                                               g_visited;

void                                                            pre_setting(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}

void                                                            input_action(void)
{
    int                                                         index;

    std::cin >> g_row_size;
    g_matrix_size = g_row_size * g_row_size;
    g_map.resize(g_matrix_size);
    g_alt.resize(g_matrix_size);
    g_unique_alt.resize(g_matrix_size);
    g_displacement = { {0, 1}, {0, -1}, {1, 0}, {-1 ,0}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1} };
    g_result = 1e6;
    index = -1;
    while (++index < g_matrix_size)
    {
        std::cin >> g_map[index];
        if (g_map[index] == 'P')
            g_post_office = std::make_pair(index / g_row_size, index % g_row_size);
        else if (g_map[index] == 'K')
            g_houses.push_back(std::make_pair(index / g_row_size, index % g_row_size));
    }
    index = -1;
    while (++index < g_matrix_size)
    {
        std::cin >> g_alt[index];
        g_unique_alt[index] = g_alt[index];
    }
    std::sort(g_unique_alt.begin(), g_unique_alt.end());
    g_unique_alt.erase(std::unique(g_unique_alt.begin(), g_unique_alt.end()), g_unique_alt.end());
}

void                                                            depth_search(int x, int y, int min_alt, int max_alt)
{
    int                                                         index;

    index = -1;
    if (x < 0 || y < 0 || x >= g_row_size || y >= g_row_size || g_visited[x * g_row_size + y]
            || min_alt > g_alt[x * g_row_size + y] || max_alt < g_alt[x * g_row_size + y])
        return ;
    g_visited[x * g_row_size + y] = true;
    while (++index < 8)
        depth_search(g_displacement[index].first + x, g_displacement[index].second + y, min_alt, max_alt);
}

bool                                                            is_possible(void)
{
    int                                                         index;
    int                                                         count;
    int                                                         number_of_house;

    index = -1;
    count = 0;
    number_of_house = static_cast<int>(g_houses.size());
    while (++index < number_of_house)
        if (g_visited[g_houses[index].first * g_row_size + g_houses[index].second])
            ++count;
    return count == number_of_house;
}

void                                                            two_pointer_search(void)
{
    int                                                         search_size;
    int                                                         s_index;
    int                                                         e_index;

    search_size = static_cast<int>(g_unique_alt.size());
    s_index = 0;
    e_index = 0;
    while (e_index < search_size)
    {
        while (s_index < search_size)
        {
            g_visited = std::vector<bool>(g_matrix_size, false);
            depth_search(g_post_office.first, g_post_office.second, g_unique_alt[s_index], g_unique_alt[e_index]);
            if (!is_possible())
                break ;
            if (g_result > g_unique_alt[e_index] - g_unique_alt[s_index])
                g_result = g_unique_alt[e_index] - g_unique_alt[s_index];
            ++s_index;
        }
        ++e_index;
    }
}

void                                                            output_action(void)
{
    std::cout << g_result;
}

void                                                            solution(void)
{
    input_action();
    two_pointer_search();
    output_action();
}

int                                                             main(void)
{
    pre_setting();
    solution();
    return (0);
}
