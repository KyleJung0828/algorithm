#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

typedef pair<int, int> pi;

int solution(vector<int> food_times, long long k) 
{
    // ������������ sorting�Ͽ� ���� ù element��ŭ ���������� ���� �� ����. 
    // Sorting �� ���� index�� ã�� ���� pair�� ����
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

    vector<int> sortedData; // sorting�� indices
    for(size_t i = 0 ; i < originalPairs.size() ; ++i)
        sortedData.push_back(originalPairs[i].first);
    int n = sortedData.size();

    long long timeLapsed = 0;
    // ó������ sortedData[0] �� n - 0 ��ŭ ���� �� ����
    // �� �������� sortedData[1] �� n - 1 ��ŭ ���� �� ����
    // ...
    // sortedData[j]�� n - j ��ŭ ���� �� ����
    // timeLapsed�� ������� ���� �ð��� ��´�
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
        
        // ���� timeLapsed�� K�� �Ѵ´ٸ�, �Ųٷ� ã�� index�� ã�´�.
        if(timeLapsed > k)
        {
            int sortedIndex = sortedData.size(); // ���������� ã�´�
            while(timeLapsed > k)
            {
                // ������ ó������ ã�ٰ�, ó��(j)�� �����ϸ� �ٽ� ������ Index�� ����
                sortedIndex = sortedIndex == j ? sortedData.size() - 1 : sortedIndex - 1; 
                --timeLapsed;
            }

            // ã�� Index�� ���� Index�� ��Ī�Ͽ� ����
            return originalPairs[sortedIndex].second + 1;
        }
    }

    // for loop�� �����µ��� K�� ������ �ʾҴٸ� �� �Ծ��ٴ� ���̹Ƿ� -1 ����
    return -1;
}

int main(int argc, char* argv[])
{
    vector<int> input = {1, 1, 3, 4, 5, 6};
    int res = solution(input, 10);
    cout << "Solution is : " << res << endl;
    return 0;
}
