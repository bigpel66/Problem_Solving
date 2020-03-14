#include <iostream>
using namespace std;

int DP[11] = {0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    DP[0] = 1;
    DP[1] = 2;
    DP[2] = 4;
    
    int testcase;
    int number;
    
    cin >> testcase;
    
    for(int i = 0; i < testcase; i++)
    {
        cin >> number;
        for(int j = 3; j < number; j++)
        {
            DP[j] = DP[j - 1] + DP[j - 2] + DP[j - 3];
        }
        cout << DP[number - 1] << "\n";
    }
    return 0;
}
