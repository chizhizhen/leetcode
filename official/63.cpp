#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        
        if (obstacleGrid[0][0] == 1) return res[0][0] = 0;
        else res[0][0] = 1;
        
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 1) res[i][0] = 0;
            else res[i][0] = res[i-1][0]; 
        }
        for (int i = 1; i < n; i++) {
            if (obstacleGrid[0][i] == 1) res[0][i] = 0;
            else res[0][i] = res[0][i-1]; 
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) res[i][j] = 0;
                else res[i][j] = res[i-1][j] + res[i][j-1];
            }
        }
        
        return res[m-1][n-1];
    }
};

int main(int argc, char* argv[]) {
    int A = atoi(argv[1]);
    int B = atoi(argv[2]);
    Solution solution;
    int out = solution.uniquePaths(A, B);
    
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
