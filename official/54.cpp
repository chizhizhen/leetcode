#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        if (m == 0 || n == 0) return res;
        int l = 0;
        int r = n-1;
        int t = 0;
        int b = m-1;

        // break的条件是该行或该列遍历完了，--或者++判断是非越界
        while(true) {
            for (int i = l;i <= r;i++) {
                cout << "1 " << matrix[t][i] << endl;
                res.push_back(matrix[t][i]);
            }
            if (++t > b) break;
            for (int i = t;i <= b;i++) {
                cout << "2 " << matrix[i][r] << endl;
                res.push_back(matrix[i][r]);
            }
            if (--r < l) break;
            for (int i = r; i >= l;i--) {
                cout << "3 " << matrix[b][i] << endl;
                res.push_back(matrix[b][i]);
            }
            if (--b < t) break;
            for (int i = b; i >= t;i--) {
                cout << "4 " << matrix[i][l] << endl;
                res.push_back(matrix[i][l]);
            }
            if (++l > r) break;
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    vector<vector<int>> A = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> B = {1,2,3,4,8,12,11,10,9,5,6,7};

    Solution solution;
    vector<int> out = solution.spiralOrder(A);
    
    for (auto c:out) {
        cout << "out: " << c << endl;
    }
    cout << "Congratulations!" << endl;
}
