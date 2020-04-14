#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int size = nums1.size();
        vector<int> nums;
        vector<int> out;
        for (int i = 0; i < m; i++) {
            nums.push_back(nums1[i]);
        }

        int l = 0;
        int r = 0;
        while (l < m && r < n) {
            if (nums[l] < nums2[r]) {
                out.push_back(nums[l]);
                l++;
            } else {
                out.push_back(nums2[r]);
                r++;
            }
        }
        if (l < m) {
            for (int i = l; i < m; i++) {
                out.push_back(nums[i]);
            }
        }
        if (r < n) {
            for (int i = r; i < n; i++) {
                out.push_back(nums2[i]);
            }
        }
        return out;
    }
};

int main(int argc, char* argv[]) {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;
    Solution solution;
    vector<int> out = solution.merge(nums1, m, nums2, n);
    for (auto val:out) {
        cout << val << endl;
    }
    return 1;
}
