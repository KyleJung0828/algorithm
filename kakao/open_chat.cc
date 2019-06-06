#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

const string sEntered = "님이 들어왔습니다.";
const string sLeft = "님이 나갔습니다.";

struct ActionInfo {
    string action;
    string id;
    string name;
};

vector<string> solution(vector<string> record) 
{
    vector<ActionInfo> infos;
    vector<string> answer;
    unordered_map<string, string> nameMap; // map from uid to recent nickname.

    for(size_t i = 0 ; i < record.size() ; ++i)
    {
        ActionInfo info;
        string rec = record[i];
        cout << "Current record : " << rec << endl;
        
        size_t firstSpacePos = rec.find_first_of(" ");
        info.action = rec.substr(0, firstSpacePos);

        cout << "Current action : " << info.action << endl; 

        size_t secondSpacePos = rec.find_first_of(" ", firstSpacePos + 1);

        // 2번째 공백이 없는 경우는, leave
        if(secondSpacePos == string::npos)
        {
            info.id = rec.substr(firstSpacePos + 1);
            cout << "Current id : " << info.id << endl;
            auto it = nameMap.find(info.id);
            info.name = it->second;
        }
        // 2번째 공백이 있다면, Enter/Change
        else
        {
            info.id = rec.substr(firstSpacePos + 1, secondSpacePos - firstSpacePos - 1);
            cout << "Current id : " << info.id << endl;

            info.name = rec.substr(secondSpacePos + 1);
            cout << "Current name : " << info.name << endl;

            // Enter
            if(info.action.compare("Enter") == 0)
            {
                if(nameMap.find(info.id) != nameMap.end())
                    nameMap[info.id] = info.name;
                else
                    nameMap.insert(make_pair(info.id, info.name));
            }
            // Change name
            else
            {
                nameMap[info.id] = info.name;
            }
        }
        infos.emplace_back(info);
    }

    for(size_t i = 0 ; i < infos.size() ; ++i)
    {
        if(infos[i].action.compare("Enter") == 0)
        {
            answer.emplace_back(nameMap.find(infos[i].id)->second + sEntered);
        }
        else if(infos[i].action.compare("Leave") == 0)
        {
            answer.emplace_back(nameMap.find(infos[i].id)->second + sLeft);
        }
    }

    return answer; 
}

int main (int argc, char* argv[])
{ 
    vector<string> input = 
    {
        "Enter uid1234 Muzi",
        "Enter uid4567 Prodo",
        "Leave uid1234", 
        "Enter uid1234 Prodo", 
        "Change uid4567 Ryan",
    };

    vector<string> output = solution(input);

    cout << "---Printing out the Output---" << endl;
    for (auto ent : output)
    {
        cout << ent << "\n";
    }
}

