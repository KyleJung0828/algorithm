#include <iostream>
#include <vector>

using namespace std;

int index;
int front;
int back;

// Returns rounded up integer of value x/y
int ceilDiv(int x, int y)
{
    return (x + y - 1) / y;
}

int findTarget(vector<int>& nums, int target)
{
    if (nums[index] == target)
        return index;

    if (index > back || index < front)
        return -1;

    if (nums[front] == target)
        return front;
    if (nums[back] == target)
        return back;

    if ((nums[front] <= nums[index] && target >= nums[front] && target <= nums[index])
            || nums[index] <= nums[back] && (target < nums[index] || target > nums[back]))
    {
        // go left
        back = index - 1;
        index -= ceilDiv(index - front, 2);
    }
    else if ((nums[index] <= nums[back] && target >= nums[index] && target <= nums[back])
            || nums[front] <= nums[index] && (target < nums[front] || target > nums[index]))
    {
        // go right
        front = index + 1;
        index += ceilDiv(back - index, 2);
    }
    else
        return -1;

    return findTarget(nums, target);
}

int search(vector<int>& nums, int target) 
{
    if (nums.size() == 0)
        return -1;

    index = ceilDiv(nums.size() - 1, 2);     
    front = 0; 
    back = nums.size() - 1;
    return findTarget(nums, target);
}

int main(int argc, char* argv[])
{
    vector<int> input = {2, 3, 4, 6, 7, 0, 1};
    int target = 7;

    cout << "Answer is : " << search(input, target) << endl;

    return 0;
}
