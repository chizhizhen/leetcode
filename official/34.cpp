#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res = {-1, -1};
        if (n == 0) return res;
        if (nums[0] > target || nums[n-1] < target) return res;
        int l = 0;
        int r = n - 1;
        while (l <= r) {
            if (nums[l] == target && nums[r] == target) return {l, r};
            int m = l + (r-l)/2;
            if (nums[m] < target) l = m + 1;
            else if (nums[m] > target) r = m - 1;
            else {
                // l和r要在mid出开始搜索
                l = m;
                r = m;
                while(l>=0 && nums[l] == target) {
                    l--;
                }
                while(r<n && nums[r] == target) {
                    r++;
                }
                return {l+1, r-1};
            }
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    vector<int> A = {1,2,3,3,3,3,4,5,9};
    int B = 3;
    Solution solution;
    vector<int> out = solution.searchRange(A, B);
    for (auto c:out) {
        cout << "out: " << c << endl;
    }
    cout << "Congratulations!" << endl;
}
