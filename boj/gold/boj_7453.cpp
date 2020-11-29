#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n";

typedef long long lld;

std::vector<int>                            g_input[4];
std::vector<int>                            g_binary;
int                                         g_array_size;
lld                                         g_count;


void                                        pre_setting(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}

void                                        input_action(void)
{
    int                                     index;

    index = -1;
    std::cin >> g_array_size;
    g_count = 0;
    while (++index < 4)
        g_input[index].reserve(g_array_size);
    g_binary.reserve(g_array_size * g_array_size);
    index = -1;
    while (++index < g_array_size)
        std::cin >> g_input[0][index] >> g_input[1][index] >> g_input[2][index] >> g_input[3][index];
}

void                                        allocate_binary(void)
{
    int                                     outer_i;
    int                                     inner_i;

    outer_i = -1;
    while (++outer_i < g_array_size)
    {
        inner_i = -1;
        while (++inner_i < g_array_size)
        {
            g_binary.push_back(g_input[2][outer_i] + g_input[3][inner_i]);
        }
    }
    std::sort(g_binary.begin(), g_binary.end());
}

void                                        binary_search(void)
{
    int                                     outer_i;
    int                                     inner_i;
    int                                     sum;
    int                                     lower;
    int                                     upper;

    outer_i = -1;
    while (++outer_i < g_array_size)
    {
        inner_i = -1;
        while (++inner_i < g_array_size)
        {
            sum = -(g_input[0][outer_i] + g_input[1][inner_i]);
            lower = std::lower_bound(g_binary.begin(), g_binary.end(), sum) - g_binary.begin();
            upper = std::upper_bound(g_binary.begin(), g_binary.end(), sum) - g_binary.begin();
            g_count += static_cast<lld>(upper - lower);
        }
    }
}

void                                        output_action(void)
{
    std::cout << g_count;
}

void                                        solution(void)
{
    input_action();
    allocate_binary();
    binary_search();
    output_action();
}

int                                         main(void)
{
    pre_setting();
    solution();
    return (0);
}
