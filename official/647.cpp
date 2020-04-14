#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int out = 0;
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                string sub = s.substr(i, len);
                if (isTrue(sub)) {
                    cout << len << " "<< i << endl;
                    cout << sub << endl;
                    out++;
                }
            }
        }
        return out;
    }
    bool isTrue(string s) {
        return s == string(s.rbegin(), s.rend());
    }
    //DP思想 5.cpp
    int countSubstringsDP(string s) {
        int n = s.size();
        int out = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        for (int j = 0; j < n; j++) {
            for (int i = 0; i <= j; i++) {
                if (i == j) {
                    dp[i][j] = 1;
                    out++;
                }
                else if (j - i == 1) {
                    dp[i][j] = s[i] == s[j];
                    out++;
                }
                else if (j - i > 1) {
                    dp[i][j] = s[i] == s[j] && dp[i+1][j-1];
                    out++;
                }
            }
        }
        //return dp[n-1][n-1];
        return out;
    }
};

int main(int argc, char* argv[]) {
    string A = "aaa";
    
    Solution solution;
    //int out = solution.countSubstrings(A);
    int out = solution.countSubstringsDP(A);
    
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
