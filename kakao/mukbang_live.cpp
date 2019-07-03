#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

typedef pair<int, int> pi;

int solution(vector<int> food_times, long long k) 
{
    // 오름차순으로 sorting하여 가장 첫 element만큼 공통적으로 줄일 수 있음. 
    // Sorting 후 원래 index를 찾기 위해 pair로 제작
    vector<pi> originalPairs;
    for(size_t i = 0; i < food_times.size() ; ++i)
    {
        originalPairs.push_back(make_pair(food_times[i], i));
    }

    sort(originalPairs.begin(), originalPairs.end(), [](pi& a, pi& b)
            {
            return a.first < b.first;
            }
        );

    vector<int> sortedData; // sorting된 indices
    for(size_t i = 0 ; i < originalPairs.size() ; ++i)
        sortedData.push_back(originalPairs[i].first);
    int n = sortedData.size();

    long long timeLapsed = 0;
    // 처음에는 sortedData[0] 을 n - 0 만큼 줄일 수 있음
    // 그 다음에는 sortedData[1] 을 n - 1 만큼 줄일 수 있음
    // ...
    // sortedData[j]를 n - j 만큼 줄일 수 있음
    // timeLapsed에 현재까지 줄인 시간을 담는다
    for(size_t j = 0 ; j < sortedData.size() ; ++j)
    {
        // find the next index with nonzero element
        if(sortedData[j] == 0)
            continue;

        // we can reduce each food as much as the front nonzero data, which is sortedData[j]
        int reduce = sortedData[j];

        // save time lapsed
        timeLapsed += reduce * (sortedData.size() - j);
        for(int q = j ; q < sortedData.size() ; ++q)
        {
            // reduce time
            sortedData[q] -= reduce;
        }
        
        // 만약 timeLapsed가 K를 넘는다면, 거꾸로 찾아 index를 찾는다.
        if(timeLapsed > k)
        {
            int sortedIndex = sortedData.size(); // 끝에서부터 찾는다
            while(timeLapsed > k)
            {
                // 끝에서 처음까지 찾다가, 처음(j)에 도달하면 다시 끝으로 Index를 변경
                sortedIndex = sortedIndex == j ? sortedData.size() - 1 : sortedIndex - 1; 
                --timeLapsed;
            }

            // 찾은 Index를 원래 Index와 매칭하여 리턴
            return originalPairs[sortedIndex].second + 1;
        }
    }

    // for loop이 끝났는데도 K가 끝나지 않았다면 다 먹었다는 뜻이므로 -1 리턴
    return -1;
}

int main(int argc, char* argv[])
{
    vector<int> input = {1, 1, 3, 4, 5, 6};
    int res = solution(input, 10);
    cout << "Solution is : " << res << endl;
    return 0;
}
