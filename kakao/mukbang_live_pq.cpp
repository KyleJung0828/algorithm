#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

typedef long long ll;

int solution(vector<int> food_times, long long k) 
{
    int n = food_times.size();

    // 전체 음식을 먹기 위한 양을 t에 저장
    ll t = 0;
    for (int i : food_times)
        t += i;

    // 전체 음식을 k 초 동안 다 먹을 수 있다면 더 먹을 게 없으므로 -1 리턴
    if(t <= k)
        return -1;

    vector<bool> valid(n, true);

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;

    for (int i = 0; i < n; i++)
        q.push(make_pair(food_times[i], i));

    t = 0;

    while (k >= (q.top().first - t) * q.size())
    {
        k -= (q.top().first - t) * q.size();

        t = q.top().first;

        valid[q.top().second] = false;

        q.pop();
    }

    k %= q.size();

    for(int i = 0; i < n; i++)
    {
        if (valid[i] == true)
        {
            if (k == 0)
            {
                return i+1;
            }
            k--;
        }
        else
        {
            continue;
        }
    }
    return -1;
}
