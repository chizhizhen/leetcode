class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty() || triangle[0].empty()) return 0;
        int m = triangle.size();
        if (m == 1) return triangle[0][0];
        //[i][j]处的最小路径和
        vector<vector<int>> dp(triangle);
        dp[0][0] = triangle[0][0];
        dp[1][0] = dp[0][0] + triangle[1][0];
        dp[1][1] = dp[0][0] + triangle[1][1];
        for (int i = 2; i < m; i++) {
            int n = triangle[i].size();
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                } else if (j == n-1) {
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                } else {
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
                }
            }
        }
        int minv = INT_MAX;
        for (int k = 0; k < dp[m-1].size(); k++) {
            if (minv > dp[m-1][k]) minv = dp[m-1][k];
        }
        return minv;
    }
};