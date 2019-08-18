#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    vector<int> nonEmptyVec = {1, 2, 3, 4, 5};
    vector<int> emptyVec = {};

        
    cout << "nonEmptyVec.size() - 1 = " << nonEmptyVec.size() - 1 << endl;
    cout << "emptyVec.size() - 1 = " << emptyVec.size() - 1 << endl;
    
    if(nonEmptyVec.size() - 1 > 0)
        cout << "OKAY" << endl;
    else
        cout << "You should not be entering here" << endl;
    
    if(emptyVec.size() - 1 > 0)
        cout << "You should not be entering here" << endl;
    else
        cout << "OKAY" << endl;

    return EXIT_SUCCESS;
}

    
