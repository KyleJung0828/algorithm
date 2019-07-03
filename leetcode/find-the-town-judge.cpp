#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

int findJudge(int N, vector<vector<int>>& trust) 
{
    // the point with [in-degree] - [out-degree] == N - 1 becomes the judge.
    vector<int> votes(N + 1, 0); // Note that votes[0] is never used.

    for(auto& t : trust)
    {
        --votes[t[0]];
        ++votes[t[1]];
    }

    for(size_t i = 1 ; i < votes.size() ; ++i)
    {
        if(votes[i] == N - 1)
            return i;
    }

    return -1;
}

int main(int argc, char* argv[])
{
    vector<vector<int>> input = {{1, 3}, {2, 3}};

    int res = findJudge(3, input);

    return 0;
}

