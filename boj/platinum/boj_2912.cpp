#include <iostream>
#include <vector>

using	pii = std::pair<int, int>;

int		g_number_of_dwarf;
int		g_number_of_color;
int		g_number_of_picture;
std::vector<int> g_hat;
std::vector<pii> g_range;
std::vector<std::string> g_answer;

void	pre_setting(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
}

void	input_action(void)
{
	int	i;

	std::cin >> g_number_of_dwarf >> g_number_of_color;
	g_hat = std::vector<int>(g_number_of_dwarf, 0);
	i = -1;
	while (++i < g_number_of_dwarf)
		std::cin >> g_hat[i];
	std::cin >> g_number_of_picture;
	g_range = std::vector<pii>(g_number_of_picture, std::make_pair(0, 0));
	g_answer.reserve(g_number_of_picture);
	i = -1;
	while (++i < g_number_of_picture)
		std::cin >> g_range[i].first >> g_range[i].second;
}

void	output_action(void)
{
	int	i;

	i = -1;
	while (++i < g_number_of_picture)
		std::cout << g_answer[i] << '\n';
}

void	solution(void)
{
	input_action();
	output_action();
}

int		main(void)
{
	pre_setting();
	solution();
	return (0);
}
