#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <map>
#include <functional>

using namespace std;

class FreqStack {
public:
	unordered_map<int, int> m_freqMap; // map<x, freq>
	map<int, stack<int>, greater<int>> m_group; // map<freq, stack> 

	FreqStack() 
	{
	}

	void push(int x) 
	{
		auto freqIt = m_freqMap.find(x);

		// Update New Frequency for x.
		int newFreq = (freqIt != m_freqMap.end()) ? ++(freqIt->second) : 1;

		m_freqMap.insert(make_pair(x, newFreq));

		auto groupIt = m_group.find(newFreq);
		if(groupIt != m_group.end())
		{
			groupIt->second.push(x);

		}
		else
		{
			stack<int> newStack;
			newStack.push(x);
			m_group.insert(make_pair(newFreq, newStack));
		}
	}

	int pop() 
	{
		// pop from m_group. if the popping remains an empty stack, delete that pair.
		int res = m_group.begin()->second.top();
		m_group.begin()->second.pop();

		if(m_group.begin()->second.empty())
		{
			m_group.erase(m_group.begin());
		}

		if(m_freqMap[res] > 0)
		{
			--m_freqMap[res];
		}
		else
		{
			m_freqMap.erase(m_freqMap[res]);   
		}

		return res;
	} 
};

int main(int argc, char* argv[])
{

    FreqStack* obj = new FreqStack();


    vector<int> vec;

    if(vec.size() - 1 > 0)
    {
        cout << "Why are you here?" << endl;
    }
    else
    {
        cout << "This is correct!" << endl;
    }

    obj->push(1);
    obj->push(1);
    obj->push(1);
    obj->push(2);
    obj->pop();
    obj->pop();
    obj->push(2);
    obj->push(2);
    obj->push(1);
    obj->pop();
    obj->pop();
    obj->pop();

    return 0;
}
