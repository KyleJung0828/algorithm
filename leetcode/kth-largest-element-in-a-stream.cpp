#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class KthLargest {

public:
	KthLargest(int k, vector<int>& nums)
	{
		m_nums = nums;
		m_k = k;

		sort(m_nums.begin(), m_nums.end(), [](int& a, int& b)
				{
				return a > b; 
				});
	}

	int add(int val) 
	{
		// m_nums already sorted in descending order

		bool bInserted(false);
		for(auto it = m_nums.begin() ; it != m_nums.end() ; ++it)
		{
			if(*it < val)
			{
				m_nums.insert(it, val);
				bInserted = true;
				break;
			}
		}

		if(!bInserted)
			m_nums.push_back(val);

		return m_nums[m_k - 1];
	}

private:
	vector<int> m_nums;
	int m_k;
};

int main(int argc, char* argv[])
{
	vector<int> arr = {4, 5, 8, 2};	
	int k = 3;
	KthLargest* kl =new KthLargest(k, arr);
	kl->add(3);
	kl->add(5);
	kl->add(10);

	return 0;
}

