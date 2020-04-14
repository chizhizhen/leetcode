#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        res[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) {
            res[i][0] = grid[i][0] + res[i-1][0];
        }
        for (int i = 1; i < n; i++) {
            res[0][i] = grid[0][i] + res[0][i-1];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                res[i][j] = min(res[i-1][j], res[i][j-1]) + grid[i][j];
            }
        }
        return res[m-1][n-1];
    }
private:
    int min(int x, int y) {
        return x < y?x:y;
    }
};

int main(int argc, char* argv[]) {
    vector<vector<int>> A = {{1,3,1},{1,5,1},{4,2,1}};
    
    Solution solution;
    int out = solution.minPathSum(A);
    
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
