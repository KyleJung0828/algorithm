#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) 
{
    int res(0); 

    vector<int> top(grid.front().size());
    vector<int> left(grid.size());

    fill(top.begin(), top.end(), 0);
    fill(left.begin(), left.end(), 1);

    for (int i = 0 ; i < grid.size() ; ++i)
    {
        for (int j = 0 ; j < grid[i].size() ; ++j) 
        {
            if (top[j] < grid[i][j])
                top[j] = grid[i][j];

            if (left[i] < grid[i][j])
                left[i] = grid[i][j];
        }
    }

    for (int i = 0 ; i < grid.size() ; ++i)
    {
        for (int j = 0 ; j < grid[i].size() ; ++j)
        {
            res += max(min(top[j], left[i]) - grid[i][j], 0); 
        }
    }

    return res;
}

int main (int argc, char* argv[])
{
    vector<vector<int>> input = {{3, 0, 8, 4},
                                 {2, 4, 5, 7},
                                 {9, 2, 6, 3},
                                 {0, 3, 1, 0}};
    int res = maxIncreaseKeepingSkyline(input);

    std::cout << "Result : " << res << std::endl;

    return 0;
}
