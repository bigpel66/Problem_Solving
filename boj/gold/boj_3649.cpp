#include <iostream>
#include <vector>
#include <algorithm>

int                                                             g_hole_width;
int                                                             g_number_of_lego;
std::vector<int>                                                g_lego;

void                                                            pre_setting(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}

void                                                            input_action(void)
{
    int                                                         index;

    index = -1;
    g_hole_width *= 10000000;
    g_lego.resize(g_number_of_lego);
    while (++index < g_number_of_lego)
        std::cin >> g_lego[index];
    std::sort(g_lego.begin(), g_lego.end());
}

void                                                            binary_search(void)
{
    int                                                         start;
    int                                                         end;
    int                                                         mid;
    int                                                         index;

    index = -1;
    while (++index < g_number_of_lego)
    {
        start = index + 1;
        end = g_number_of_lego - 1;
        while (start <= end)
        {
            mid = (start + end) / 2;
            if (g_lego[mid] + g_lego[index] < g_hole_width)
                start = mid + 1;
            else if (g_lego[mid] + g_lego[index] > g_hole_width)
                end = mid - 1;
            else
            {
                std::cout << "yes " << g_lego[index] << " " << g_lego[mid] << "\n";
                return ;
            }
        }
    }
    std::cout << "danger\n";
}

void                                                            solution(void)
{
    while (std::cin >> g_hole_width >> g_number_of_lego)
    {
        input_action();
        binary_search();
    }
}

int                                                             main(void)
{
    pre_setting();
    solution();
    return (0);
}
