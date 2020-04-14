#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int removeDuplicates_I(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        vector<int> diffs;
        for (int i = 0; i < n - 1; i++) {
            diffs.push_back(prices[i+1] - prices[i]);
        }
        int out = 0;
        int sum = 0;
        for (int i = 0; i < n - 1; i++) {
            if (sum > 0) {
                sum += diffs[i];
            } else sum = diffs[i];
            out = max(out, sum);
        }
        return max(out, 0);
    }
    int removeDuplicates_II(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        vector<int> diffs;
        for (int i = 0; i < n - 1; i++) {
            diffs.push_back(prices[i+1] - prices[i]);
        }
        int out = 0;
        for (auto& o:diffs) {
            if (o > 0) out += o;
        }
        return out;
    }
    int removeDuplicates_III(vector<int>& prices) {
        //same as IV when k = 2;
    }
    int maxProfit_IV(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 1 || k < 1) return 0;
        if (k >= n / 2) {
            int res = 0;
            for (int i = 0; i < n - 1; i++) {
                if (prices[i+1] > prices[i]) {
                    res += prices[i+1] - prices[i];
                }
            }
            return res;
        }
        else {
            vector<vector<int>> dp(k+1, vector<int>{0, INT_MIN});
            for (int i = 0; i < n; i++) {
                for (int j = k; j > 0; j--) {
                    dp[j][0] = max(dp[j][0], dp[j][1] + prices[i]);//不持股
                    dp[j][1] = max(dp[j][1], dp[j-1][0] - prices[i]);
                }
            }
            return dp[k][0];
        }
    }
    //309.cpp
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        vector<vector<int>> dp(n, vector<int>(3, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][2] - prices[i]);
            dp[i][2] = dp[i-1][0];
        }
        return max(dp[n-1][0], dp[n-1][2]);
    }
};
