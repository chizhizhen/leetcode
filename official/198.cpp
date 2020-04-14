#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> dp(n+1, 0);
        dp[1] = nums[0];
        dp[2] = max(nums[0], nums[1]);
        for (int i = 3; i <= n; i++) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
        }
        return dp[n];
    }
    int rob2(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> dp(n+1, 0);
        dp[1] = nums[0];
        //no nums[n-1]
        dp[2] = max(nums[0], nums[1]);
        for (int i = 3; i < n; i++) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
        }
        dp[n] = dp[n-1];
        int maxval = dp[n];
        //no nums[0]
        dp[2] = nums[1];
        dp[3] = max(nums[1], nums[2]);
        for (int i = 4; i <= n; i++) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
        }
        maxval = max(maxval, dp[n]);
        return maxval;
    }
    int rob3(TreeNode* root) {
        if (root == NULL) return 0;
    }
};

int main(int argc, char* argv[]) {
    vector<int> A = {1, 2, 3, 1};
    
    Solution solution;
    int out = solution.rob(A);
    
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
