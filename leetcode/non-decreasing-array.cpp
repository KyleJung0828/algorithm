#include <vector>
#include <iostream>
#include <limits>

using namespace std;

int cnt = 0;

bool isNonDecreasing(vector<int>& nums, int startIndex, int dropIndex)
{
    int prev = nums[startIndex];
    for(int i = startIndex + 1 ; i < static_cast<int>(nums.size()) ; ++i)
    {
        if(i == dropIndex)
            continue;

        if(prev > nums[i])
            return false;
    }
    return true;
}

bool checkPossibility(vector<int>& nums)
{
    if(nums.size() <= 1)
    {
        return true;
    }

    // Idea : Go through nums until you see the sequence [ ... <= i - 1 > i <= ... ]
    // Then you can test two cases:
    // 1. Drop i - 1 and test non-decreasingness 
    // 2. Drop i and test non-decreasingness
    // If either case fails, it's not non-decreasing, so return false.
    int prev = numeric_limits<int>::min();
    for(int i = 0 ; i < static_cast<int>(nums.size()) ; ++i)
    {
        if(prev <= nums[i])
        {
            // Okay. Non-decreasing. Update prev.
            prev = nums[i];
        }
        else
        {
            // Not okay. Decreasing. So these tests must all satisfy.
            // 1. Drop i - 1 and  test non-decreasingness from i - 2 until the end
            // 2. drop i and test from i - 1 to the end
            
            // Add Special Case where i = 1, which means i - 2 is invalid.
            bool bTestIMinusTwo = ((i - 2) < 0 ) ? 
                isNonDecreasing(nums, i, i - 1) :
                isNonDecreasing(nums, i - 2, i - 1);

            if(bTestIMinusTwo)
                ++cnt;
            else
            {
                bool bTestIMinusOne = isNonDecreasing(nums, i - 1, i);
                if(bTestIMinusOne)
                    ++cnt;
                else
                    return false;
            }
        }

        if(cnt > 1)
            return false;
    }

    return true;
}

int main(int argc, char* argv[])
{
    string firstLine;
    vector<int> input;

    while(getline(cin, line))

    cin >> 
    return 0;
}
