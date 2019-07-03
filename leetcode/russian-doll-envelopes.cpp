#include <vector>
#include <queue>
#include <algorithm>
#include <string>


using namespace std;

typedef pair<int, int> pi;
int maxEnvelopes(vector<vector<int>>& envelopes) 
{
    if(envelopes.size() == 0)
        return 0;

    vector<pi> envs;

    for(auto& env : envelopes)
    {
        envs.emplace_back(make_pair(env[0], env[1]));
    }

    // sort ascending order of width & height.
    sort(envs.begin(), envs.end(), [](pi& a, pi& b)
            {
            if(a.first == b.first)
            {
            return a.second < b.second;
            }
            else
            {
            return a.first < b.first;
            }
            }
        );

    string hi = "Hello!";

    vector<int> lis(envs.size());
    lis[0] = 1;

    int subLis(0);

    for(size_t i = 1 ; i < envs.size() ; ++i)
    {
        subLis = 0;

        for(size_t j = 0 ; j < i ; ++j)
        {
            if(envs[i].first > envs[j].first && envs[i].second > envs[j].second)
            {
                subLis = lis[j] > subLis ? lis[j] : subLis; // update subLis
            }
        }

        lis[i] = subLis + 1;
    }

    return *max_element(lis.begin(), lis.end());
}

int main(int argc, char* argv[])
{
    vector<vector<int>> input = {{15,8},{2,20},{2,14},{4,17},{8,19}};
    int res = maxEnvelopes(input);

    return 0;
}
