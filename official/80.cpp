#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int s = 1;
        for (int f = 2; f < n; f++) {
            if (nums[s-1] != nums[f]) {
                nums[++s] = nums[f];
            }
        }
        return s+1;
    }
};

int main(int argc, char* argv[]) {
    vector<int> A = {0,0,1,1,1,1,2,3,3};
    
    Solution solution;
    int out = solution.removeDuplicates(A);
    
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
