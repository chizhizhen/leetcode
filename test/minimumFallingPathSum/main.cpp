#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int getValue(vector<vector<int>> A) {
        int m = A.size();
        int n = A[0].size();
        int out = INT_MAX;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int  i = 0; i < n; i++) {
            dp[0][i] = A[0][i];
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    dp[i][j] = A[i][j] + min(dp[i-1][j], dp[i-1][j+1]);
                } else if (j + 1 == n) {
                    dp[i][j] = A[i][j] + min(dp[i-1][j], dp[i-1][j-1]);
                } else {
                    dp[i][j] = A[i][j] + min(dp[i-1][j], dp[i-1][j+1], dp[i-1][j-1]);
                }
            
                if (i + 1 == m) {
                    out = min(out, dp[i][j]);
                }
            }
        }
        
        /*
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << "i: " << i << ", j: " << j << ", " << dp[i][j] <<endl;
            } 
        } */

        return out;
    }
private:
    int min(int x, int y) {
        return x<y?x:y;
    }
    int min(int x, int y, int z) {
        return min(x, min(y, z));
    }
};

int main(int argc, char* argv[]) {
    vector<vector<int>> A = {{1,2,3},{4,5,6},{7,8,9}};
    Solution solution;
    int out = solution.getValue(A);
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
