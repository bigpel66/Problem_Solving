#include <string>
#include <map>
#include <vector>

using namespace std;

vector<string> str;
vector<pair<string, string>> uidWithState;
map<string, string> uidWithName;

void setUidWithState(string &s)
{
    str.clear();
    
    string temp;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ')
        {
            str.push_back(temp);
            temp = "";
        }
        else
        {
            temp += s[i];
        }
    }
    str.push_back(temp);
}

vector<string> solution(vector<string> record) {
    for(int i = 0; i < record.size(); i++)
    {
        setUidWithState(record[i]);
        
        if(str[0][0] == 'E')
        {
            uidWithName[str[1]] = str[2];
            uidWithState.push_back(make_pair(str[0], str[1]));
        }
        else if(str[0][0] == 'L')
        {
            uidWithState.push_back(make_pair(str[0], str[1]));
        }
        else
        {
            uidWithName[str[1]] = str[2];
        }
    }
    
    vector<string> answer;
    
    for(int i = 0; i < uidWithState.size(); i++)
    {
        string temp;
        temp += uidWithName[uidWithState[i].second];
        temp += "님이 ";
        
        
        if(uidWithState[i].first == "Enter")
        {
            temp += "들어왔습니다.";
            answer.push_back(temp);
        }
        else
        {
            temp += "나갔습니다.";
            answer.push_back(temp);
        }
    }
    
    return answer;
}
