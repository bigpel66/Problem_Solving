#include <iostream>
#include <vector>
#define endl "\n"

std::vector<std::string> givenStrings;
int dp[1001][1001];

int max(int &a, int &b)
{
    return a > b ? a : b;
}

void inputAction()
{
    for (int i = 0; i < 2; i++)
    {
        std::string temp;
        std::cin >> temp;
        givenStrings.push_back(temp);
    }
}

void calcLCS()
{
    for (size_t i = 1; i <= givenStrings[0].length(); i++)
    {
        for (size_t j = 1; j <= givenStrings[1].length(); j++)
        {
            if (givenStrings[0][i - 1] == givenStrings[1][j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
}

void outputAction()
{
    std::cout << dp[givenStrings[0].length()][givenStrings[1].length()] << endl;
}

void solution()
{
    inputAction();
    calcLCS();
    outputAction();
}

int main(void)
{
    solution();

    return 0;
}