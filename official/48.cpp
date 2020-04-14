#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        //corner point
        //i:0, j:0,1,2; i:1, j:0,1; i:2, j:0
        for (int i = 0; i < n;i++) {
            for (int j = 0; j < n-i-1; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][n-i-1];
                matrix[n-j-1][n-i-1] = tmp;
            }
        }

        //line flip
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n/2; j++) {
                int tmp = matrix[j][i];
                matrix[j][i] = matrix[n-j-1][i];
                matrix[n-j-1][i] = tmp;
            }
        }
    }
};

int main(int argc, char* argv[]) {
    vector<vector<int>> A = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    vector<vector<int>> B = {{15,13,2,5},{14,3,4,1},{12,6,8,9},{16,7,10,11}};
    Solution solution;
    solution.rotate(A);
    for (auto i:A) {
        for (auto j :i) {
            cout << j << endl;
        }
    }
    cout << "Congratulations!" << endl;
}
