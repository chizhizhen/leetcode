#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        int out = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j);
                    out++;
                }
            }
        }
        return out;
    }
    void dfs(vector<vector<int>>& grid, int x, int y) {
        if (grid[x][y] == 0) return;
        grid[x][y] = 0;
        for (int i = 0; i < shift.size(); i++) {
            int xn = x + shift[i][0];
            int yn = y + shift[i][1];
            if (xn>=0 && yn>=0 && xn< grid.size() && yn<grid[0].size()) {
                if (grid[xn][yn] == 0) continue;
                dfs(grid, xn, yn);
            }
        }
        return;
    }
private:
    vector<vector<int>> shift = {{-1,0},{1,0},{0,1},{0,-1}};
};

int main(int argc, char* argv[]) {
    vector<vector<int>> A = {{1,1,1,1,0},{1,1,0,1,0},{1,1,0,0,0},{0,0,0,0,0}};
    
    Solution solution;
    int out = solution.numIslands(A);
    
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
