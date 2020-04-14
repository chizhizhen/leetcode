#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int l = 0;
        int r = n - 1;
        int t = 0;
        int b = n - 1;
        vector<vector<int>> res(n, vector<int>(n, 0));
        int ind = 1;
        while (true) {
            for (int i = l; i <= r; i++) {
                res[t][i] = ind++;
            }
            if (++t > b)  break;
            for (int i = t; i <= b; i++) {
                res[i][r] = ind++;
            }
            if (--r < l)  break;
            for (int i = r; i >= l; i--) {
                res[b][i] = ind++;
            }
            if (--b < t)  break;
            for (int i = b; i >= t; i--) {
                res[i][l] = ind++;
            }
            if (++l > r)  break;
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    int A = 3;
    
    Solution solution;
    vector<vector<int>> out = solution.generateMatrix(A);
    
    for (auto a:out) {
        cout << "#####" << endl;
        for (auto b:a) {
            cout << "out: " << b << endl;
        }
    }
    cout << "Congratulations!" << endl;
}
