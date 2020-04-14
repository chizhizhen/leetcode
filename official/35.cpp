#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int out = -1;
        while (l < r) {
            int m = (l+r)/2;
            if (nums[m] > target) r = m - 1;
            else if (nums[m] < target) l = m + 1;
            else return m;
        }
        if (target < nums[l]) return l;
        return l+1;
    }
};

int main(int argc, char* argv[]) {
    vector<int> A = {1,3,5,6};
    int B = atoi(argv[1]);
    Solution solution;
    int out = solution.searchInsert(A, B);
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
    return 1;
}
