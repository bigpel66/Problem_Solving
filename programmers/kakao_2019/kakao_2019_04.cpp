#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> v1, pair<int, int> v2)
{
    return v1.second < v2.second;
}

int solution(vector<int> food_times, long long k) {
    vector<pair<int, int>> food;
    int size = (int)food_times.size();
    long long before = 0;
    long long approx = 0;
    
    for(int i = 0; i < size; i++)
    {
        food.push_back(make_pair(food_times[i], i + 1));
    }
    
    sort(food.begin(), food.end());
    
    for(int i = 0; i < size; i++)
    {
        before = approx;
        
        if(i == 0)
        {
            approx += food[0].first * size;
            if(approx <= k) continue;
        }
        else
        {
            approx += (food[i].first - food[i - 1].first) * (size - i);
            if(approx <= k) continue;
        }
        
        sort(food.begin() + i, food.end(), compare);
        return food[((k - before) % (size - i)) + i].second;
    }
    
    return -1;
}
