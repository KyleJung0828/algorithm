#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int scheduleCourse(std::vector<std::vector<int>>& courses) 
{
    int res(0);   

    std::sort(courses.begin(), courses.end(), 
            [] (std::vector<int>& a, std::vector<int>& b)
            {
            return a[1] < b[1];
            });

    std::priority_queue<std::vector<int>> pq;
    auto iter = courses.begin();
    int dayLapsed(0); 
    while (iter != courses.end())
    {
        while (!pq.empty() && 
                pq.top()[0] > (*iter)[0] && // prefer smaller 
                dayLapsed + (*iter)[0] > (*iter)[1]) // should add up successfully 
        {
            --res;
            dayLapsed -= pq.top()[0];
            pq.pop();
        }
        if (dayLapsed + (*iter)[0] <= (*iter)[1])
        {
            ++res; 
            dayLapsed += (*iter)[0];
            pq.push(*iter);
        }
        ++iter;
    }
    return res;
}

int main (int argc, char* argv[])
{
    std::vector<std::vector<int>> input = 
        {{{2,3},{2,3},{1,8},{5,7},{4,5},{4,8},{2,10},{1,7},{2,9},{2,10},
         {5,9},{5,7},{7,10},{3,5},{1,8},{5,8},{1,8},{5,5}}};

    int res = scheduleCourse(input);

    std::cout << "Result : " << res << std::endl;

    return 0;
}
