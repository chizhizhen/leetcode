#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int getValue(vector<vector<int>> A) {
        int m = A.size();
        int n = A[0].size();
        vector<vector<int>> out(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                out[i][j] = out[i-1][j] + out[i][j-1];
            }
        }
        return out[m-1][n-1];
    }

    int getValue2(vector<vector<int>> A) {
        int m = A.size();
        int n = A[0].size();
        vector<vector<int>> out(m, vector<int>(n, 0));
        
        out[0][0] = A[0][0] ? 0:1;
        
        for (int i = 1; i < m; i++) {
            out[i][0] = A[i][0] ? 0:out[i-1][0];
        }
        
        for (int j = 1; j < n; j++) {
            out[0][j] = A[0][j] ? 0:out[0][j-1];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                out[i][j] = A[i][j] ? 0:out[i-1][j] + out[i][j-1];
            }
        }
        return out[m-1][n-1];
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> matrix(3, vector<int>(3, 0));
    int out = solution.getValue(matrix);
    cout << "out: " << out << endl;
    matrix[1][1] = 1;
    out = solution.getValue2(matrix);
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
