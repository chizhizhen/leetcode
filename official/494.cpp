#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    //DFS
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        if (n == 0) return 0;
        int count = 0;
        int k = 0;
        int res = 0;
        dfs(count, k, res, nums, S);
        return count;
    }
    void dfs(int& count, int k, int res, vector<int>& nums, int t) {
        if (k == nums.size()) {
            if (res == t) count++;
            return;
        }
        dfs(count, k+1, res + nums[k], nums, t);
        dfs(count, k+1, res - nums[k], nums, t);
    }
    
    //
    int findTargetSumWaysDP(vector<int>& nums, int S) {
        int n = nums.size();
        if (n == 0) return 0;
        int sum = 0;
        for (auto num:nums) {
            sum += num;
        }
        if (sum > S) return 0;
        vector<vector<int>> dp(n, vector<int>(2*sum+1, 0));
        if (nums[0] == 0) {
            dp[0][sum] = 2;
        } else {
            dp[0][sum-nums[0]] = 1;
            dp[0][sum+nums[0]] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 2*sum+1; j++) {
                int l = (j-nums[i]<0)?0:j-nums[i];
                int r = (j+nums[i]<2*sum+1)?j+nums[i]:0;
                dp[i][j] = dp[i-1][l] + dp[i-1][j];
            }
        }
        return dp[n-1][sum+S];
    }
};

int main(int argc, char* argv[]) {
    vector<int> A = {1,1,1,1,1};
    int B = 3;
    
    Solution solution;
    //int out = solution.findTargetSumWays(A, B);
    int out = solution.findTargetSumWaysDP(A, B);
    
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
