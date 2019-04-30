#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

const std::string sEntered = "님이 들어왔습니다.";
const std::string sLeft = "님이 나갔습니다.";

std::vector<std::string> solution(std::vector<std::string> record) 
{
    std::vector<std::string> answer;
    std::string sAnswerEnt;
    std::string sUid;
    std::string sNickname;
    std::string sActionStatus;
   
	// map for lasted nick map. Key: user id. Map: Lastest nickname
    std::unordered_map<std::string, std::string> latestNickMap;
	// 가장 최근이 뒤 부터니까 뒤에서부터 uId에 대한 최신 nickname을 map에 담는다
    for (auto rIter = record.rbegin() ; rIter != record.rend() ; ++rIter)
	{
		int nFirstSpacePos = (*rIter).find_first_of(" "); // 첫 공백의 위치
		int nSecondSpacePos = (*rIter).substr(nFirstSpacePos + 1).find_first_of(" "); // 두 번째 공백의 위치
		std::cout << "First Space Pos : " << nFirstSpacePos << "\n";
		std::cout << "Second Space Pos : " << nSecondSpacePos << "\n";

		// 두 번째 공백이 없다면 leave
		if (nSecondSpacePos == std::string::npos)
		{
			sUid = (*rIter).substr(nFirstSpacePos + 1);
			sNickname = latestNickMap.find(sUid)->second;
			sAnswerEnt = sNickname + sLeft;
			answer.emplace_back(sAnswerEnt);
			break;
		}
		else
		{
			sUid = (*rIter).substr(nFirstSpacePos + 1, nSecondSpacePos);
			sActionStatus = (*rIter).substr(0, nFirstSpacePos);
			auto nickIter = latestNickMap.find(sUid);	

			if (nickIter == latestNickMap.end())
			{
				sNickname = (*rIter).substr(nFirstSpacePos + nSecondSpacePos + 2);
				latestNickMap.insert(std::pair<std::string, std::string>(sUid, sNickname));
			}
			else
			{
				sNickname = nickIter->second; 
			}

			if (sActionStatus.compare("Enter") == 0)
			{
				sAnswerEnt = sNickname + sEntered;
				answer.emplace_back(sAnswerEnt);
			}
			else
			{
				latestNickMap[sUid] = sNickname;
			}
		}

	}

	std::reverse(std::begin(answer), std::end(answer));

	return answer; 
}

int main (int argc, char* argv[])
{ 
	std::vector<std::string> input = 
	{"Enter uid1234 Muzi",
		"Enter uid4567 Prodo",
		"Leave uid1234", 
		"Enter uid1234 Prodo", 
		"Change uid4567 Ryan"};

	std::vector<std::string> output = solution(input);

	std::cout << "---Printing out the Output---" << std::endl;
	for (auto ent : output)
	{
		std::cout << ent << "\n";
	}
}

