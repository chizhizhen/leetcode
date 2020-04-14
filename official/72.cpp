#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    int getValue(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
                if (str1[i-1] == str2[j-1]) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                } else {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
int main() {
    string a = "sunday";
    string b = "saturday";
    Solution solution;
    int out = solution.getValue(a, b);
    cout << out << endl;
    cout << "Hello World!" << endl;
}
