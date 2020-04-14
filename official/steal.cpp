class Solution {
public:
    //198.cpp
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> dp(n+1, 0);
        dp[1] = nums[0];
        dp[2] = max(nums[0], nums[1]);
        for (int i = 3; i <= n; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
        }
        return dp[n];
    }
    //213.cpp
    int robII(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> dp(n+1, 0);
        // w/o nums[n-1]
        dp[1] = nums[0];
        dp[2] = max(nums[0], nums[1]);
        for (int i = 3; i < n; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
        }
        int maxv = dp[n-1];
        // w/o nums[0]
        dp[2] = nums[1];
        dp[3] = max(nums[1], nums[2]);
        for (int i = 4; i <= n; i++) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
        }
        return max(maxv, dp[n]);
    }
    //337.cpp
    int robIII(TreeNode* root) {
        vector<int> out;
        out = dfs(root);
        return max(out[0], out[1]);
    }
    vector<int> dfs(TreeNode* root) {
        vector<int> res(2, 0);
        if (root == NULL) return res;
        int val = root->val;
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        res[0] = max(left[0], left[1]) + max(right[0], right[1]);
        res[1] = val + left[0] + right[0];
        return res;
    }
};
