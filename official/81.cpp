#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    bool removeDuplicates(vector<int>& nums, int t) {
        if (nums.size() == 0) return false;
        int l = 0;
        int r = nums.size();
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == t) return true;
            else if (nums[m] > t) r = m - 1;
            else l = m + 1;
        }
        return nums[l] == t?true:false;
    }
};

int main(int argc, char* argv[]) {
    vector<int> A = {2,5,6,0,0,1,2};
    int T = 3;

    Solution solution;
    bool out = solution.removeDuplicates(A, T);
    
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
