#include <string>
#include <vector>
#include <algorithm>
#include <map>

using Pdi = std::pair<double, int>;
using Pii = std::map<int, int>;

bool compare(Pdi lhs, Pdi rhs)
{
    if(lhs.first == rhs.first)
    {
        return lhs.second < rhs.second;
    }
    
    else
        return lhs.first > rhs.first;
}

std::vector<int> solution(int N, std::vector<int> stages) {
    std::vector<Pdi> failureWithStages;
    std::vector<int> answer;
    Pii mapping;
    int totalTrial = (int)stages.size();
    int removeFormer = 0;
    
    for(int i = 0; i < totalTrial; i++)
    {
        mapping[stages[i]] += 1;
    }
    
    for(int i = 1; i <= N; i++)
    {
        if(mapping[i] != 0)
        {
            failureWithStages.push_back(std::make_pair(mapping[i] / (double)(totalTrial - removeFormer), i));
        }
        else
        {
            failureWithStages.push_back(std::make_pair(0, i));
        }
        
        removeFormer += mapping[i];
    }
    
    sort(failureWithStages.begin(), failureWithStages.end(), compare);
    
    for(int i = 0; i < N; i++)
    {
        answer.push_back(failureWithStages[i].second);
    }
    
    return answer;
}
