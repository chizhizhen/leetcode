#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int min_v = nums[n-1];
        int max_v = nums[0];
        int l = 0;
        int r = 0;
        for (int i = 0; i < n; i++) {
            if (max_v > nums[i]) { //当前位置不对
                r = i;
            } else max_v = nums[i];
            
            if (min_v < nums[n-1-i]) {
                l = n-1-i;
            } else min_v = nums[n-1-i];
        }
        return r-l+1;
    }
};

int main(int argc, char* argv[]) {
    vector<int> A = {2, 6, 4, 8, 10, 9, 15};
    
    Solution solution;
    int out = solution.findUnsortedSubarray(A);
    
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
