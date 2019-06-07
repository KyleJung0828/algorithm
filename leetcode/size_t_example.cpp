#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char* argv[])
{
    vector<int> myVector = {}; // empty vector

    for(int i = 0 ; i < static_cast<int>(myVector.size()) - 1 ; ++i)
    {
        cout << "you should not be here!" << endl;
        cout << "Current value of i = " << i << endl;
    }
}
