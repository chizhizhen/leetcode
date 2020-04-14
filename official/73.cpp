#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool row_flag = false;
        bool col_flag = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0) row_flag = true;
                    if (j == 0) col_flag = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        //先做m=1，n=1内的赋值，否则所有[i][0]或者[0][j]全变零了
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
                if (matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if (row_flag) {
            for (int i = 0; i < n; i++) {
                matrix[0][i] = 0;
            }
        }
        if (col_flag) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main(int argc, char* argv[]) {
    vector<vector<int>> A = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    vector<vector<int>> B = {{0,0,0,0},{0,4,5,0},{0,3,1,0}};

    Solution solution;
    solution.setZeroes(A);
    
    for (auto c:A) {
        cout << "######" << endl;
        for (auto d:c) {
            cout << "out: " << d << endl;
        }
    }
    cout << "Congratulations!" << endl;
}
