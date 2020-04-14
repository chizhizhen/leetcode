#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

//200.cpp
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int maxlen = 0;
        vector<vector<int>> memo(m, vector<int>(n, 0)); //记录每个节点可以走过的最长路径
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int len = dfs(matrix, i, j, m, n, memo);
                maxlen = max(maxlen, len);
            }
        }
        return maxlen;
    }
    int dfs(vector<vector<int>>& matrix, int x, int y, int m, int n, vector<vector<int>>& memo) {
        //终止条件
        if (memo[x][y] != 0) return memo[x][y];
        int t = 1;
        for (int i = 0; i < 4; i++) {
            int xn = x + shift[i][0];
            int yn = y + shift[i][1];
            if (xn>=0 && xn<m && yn>=0 && yn < n && matrix[xn][yn] > matrix[x][y]) {
                t = max(t, 1+ dfs(matrix, xn, yn, m, n, memo));
            }
        }
        memo[x][y] = t;
        return memo[x][y];
    }
private:
    vector<vector<int>> shift = {{-1,0},{1,0},{0,-1},{0,1}};
};

int main(int argc, char* argv[]) {
    vector<vector<int>> A = {{9,9,4},{6,6,8},{2,1,1}};
    
    Solution solution;
    int out = solution.longestIncreasingPath(A);
    
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
