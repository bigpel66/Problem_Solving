#include <iostream>
#include <vector>
#include <algorithm>

int                                                             g_row_size;
int                                                             g_matrix_size;
int                                                             g_min;
int                                                             g_max;
int                                                             g_result;
std::vector<int>                                                g_matrix;
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
    g_min = 200;
    g_max = 0;
    g_matrix.resize(g_matrix_size);
    g_displacement = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    index = -1;
    while (++index < g_matrix_size)
    {
        std::cin >> g_matrix[index];
        g_min = std::min(g_min, g_matrix[index]);
        g_max = std::max(g_max, g_matrix[index]);
    }
    g_result = g_max - g_min;
}

void                                                            depth_search(int x, int y, int min, int max)
{
    int                                                         index;
    int                                                         offset;

    index = -1;
    offset = x * g_row_size + y;
    if (x < 0 || y < 0 || x >= g_row_size || y >= g_row_size || g_visited[offset] ||
            min > g_matrix[offset] || max < g_matrix[offset])
        return ;
    g_visited[offset] = true;
    while (++index < 4)
        depth_search(x + g_displacement[index].first, y + g_displacement[index].second, min, max);
}

void                                                            two_pointer_search(void)
{
    int                                                         s_index;
    int                                                         e_index;

    s_index = g_min;
    e_index = g_min;
    while (e_index <= g_max && s_index <= g_max)
    {
        if (g_result > e_index - s_index)
        {
            g_visited = std::vector<bool>(g_matrix_size, false);
            depth_search(0, 0, s_index, e_index);
            if (!(g_visited[0] && g_visited[g_matrix_size - 1]))
            {
                ++e_index;
                continue;
            }
            g_result = e_index - s_index;
        }
        ++s_index;
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
