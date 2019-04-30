#include <map>
#include <vector>

using namespace std;

map<int, int> rcMap;

int singleNumber(vector<int>& nums)
{
#if 0x00
    for(int i = 0 ; i != nums.size() ; ++i)
    {
        ++rcMap[nums[i]];
    }

    int res;
    for(auto pair : rcMap)
    {
        if(pair.second == 1)
            res = pair.first;
    }
    return res;
    
#endif

    int res(0);
    for(auto i : nums)
        res ^= i;

    return res;
}

int main(int argc, char* argv[])
{
    vector<int> input = {3, 2, 3, 2, 1};

    int res = singleNumber(input);
}
