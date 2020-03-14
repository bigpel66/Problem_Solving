#include <string>
#include <vector>
#include <set>

bool ofAtLeast(std::vector<int> &vec, int comb)
{
    for(int i = 0; i < vec.size(); i++)
    {
        if((vec[i] & comb) == vec[i]) return false;
    }
    return true;
}

int solution(std::vector<std::vector<std::string>> relation) {
    std::vector<int> answer;
    
    int row = (int)relation.size();
    int col = (int)relation[0].size();

    for(int i = 1; i < 1<<(col); i++)
    {
        std::set<std::string> tuple;
        
        for(int j = 0; j < row; j++)
        {
            std::string temp = "";
            
            for(int k = 0; k < col; k++)
            {
                if(i & (1<<k)) temp += relation[j][k];
            }
            if(tuple.count(temp) == 0) tuple.insert(temp);
            else break;
        }
        
        if(tuple.size() == row && ofAtLeast(answer, i))
            answer.push_back(i);
    }
        
    return (int)answer.size();
}
