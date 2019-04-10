#include <string>
#include <vector>

using namespace std;

vector<string> commonChars(vector<string>& A) 
{
	vector<string> res;
	if (A.size() == 0)
		return res;

	string match = A.front();
	for(int i = 1 ; i < A.size() ; ++i)
	{
		if (match.size() == 0)
			return res;

		string temp;
		for(char ch : match)
		{
			for(auto j = A[i].begin() ; j != A[i].end() ; ++j)
			{
				if(ch == *j)
				{
					temp.push_back(ch);
					A[i].erase(j);
					break;
				}
			}
		}
		match = temp;
	}

	for(auto it = match.begin() ; it != match.end() ; ++it)
	{
		res.push_back(string(&(*it), 1));
	}

	return res;
}

int main(int argc, char* argv[])
{
    //vector<string> input = {"bella", "label", "roller"};
    vector<string> input = {"cool", "lock", "cook"};
    
    vector<string> output = commonChars(input);

    return 0;
}
