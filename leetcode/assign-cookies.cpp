#include <iostream>
#include <vector>
#include <algorithm>

int findContentChildren(std::vector<int>& g, std::vector<int>& s) 
{
    int res(0);

    if (s.size() == 0)
        return res;
    
    // first need to sort g and s
    std::sort(g.begin(), g.end()); // std::sort sorts in ascending order by default.
    std::sort(s.begin(), s.end());

    auto sIter = s.end();
    --sIter;
    for (auto gIter = g.rbegin() ; gIter != g.rend() ; ++gIter)
    {
        if (*sIter >= *gIter)
        {
            ++res;
            sIter = s.erase(sIter);
            if (s.size() == 0)
                break;
            
            --sIter;
        }
    }
    // Output the number of children who are content.
    return res;
}

int main (int argc, char* argv[])
{
    std::vector<int> g = {1, 2, 3};
    std::vector<int> s = {1, 1};

    int res = findContentChildren(g, s);

    std::cout << "Content Children : " << res << std::endl;

    return 0;
}
