#include <algorithm>
#include <iostream>
#include <vector>

int		g_no_test;
std::vector<int> g_seq;
std::vector<int> g_memoi;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	std::cin >> g_no_test;
	g_seq = std::vector<int>(g_no_test, 0);
	g_memoi = std::vector<int>(1000001, 0);
	for (int i = 0; i < g_no_test; i++)
		std::cin >> g_seq[i];
}

void	logic(void)
{
	int	hail;
	int	tmp;

	for (int i = 0; i < g_no_test; i++)
	{
		hail = g_seq[i];
		tmp = 1;
		for (; hail != 1;)
		{
			if (hail <= 100000 && g_memoi[g_seq[i]])
			{
				tmp = std::max(hail, g_memoi[g_seq[i]]);
				break ;
			}
			tmp = std::max(tmp, hail);
			if (hail % 2)
				++(hail *= 3);
			else
				hail /= 2;
		}
		g_memoi[g_seq[i]] = tmp;
	}
}

void	output_action(void)
{
	for (int i = 0; i < g_no_test; i++)
		std::cout << g_memoi[g_seq[i]] << '\n';
}

void	solution(void)
{
	input_action();
	logic();
	output_action();
}

int		main(void)
{
	pre_setting();
	solution();
	return (0);
}
