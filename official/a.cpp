#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    }
};

int main(int argc, char* argv[]) {
    vector<int> A = {0,0,1,1,1,1,2,3,3};
    
    Solution solution;
    vector<int> out = solution.removeDuplicates(A);
    
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
