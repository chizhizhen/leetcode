#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> vvec;
        vector<string> vec(n, string(n, '0'));
        int x = 0;
        help(vvec, vec, x, n);
        return vvec;
    }
    
    void help(vector<vector<string>>& vvec, vector<string>& vec, int x, int n) {
        if (x == n) {
            vvec.push_back(vec);
        }
        else {
            for (int i = 0; i < n; i++) {
                if (vec[x][i] == '.') continue;
                auto vec_h = vec;
                vec_h[x] = string(n, '.');
                vec_h[x][i] = 'Q';
                for (int j = x,number=1; j < n-1; j++,number++) {
                    vec_h[j + 1][i] = '.';
                    if(number+i<n) vec_h[j + 1][i+number] = '.';
                    if(i-number>-1)vec_h[j+1][i-number]='.';
                }
                if (x<n-1&&vec[x+1] == string(n, '.')) break;
                help(vvec, vec_h, x + 1, n);
            }
        }
    }
};

int main(int argc, char* argv[]) {
    int A = atoi(argv[1]);
    int B = atoi(argv[2]);
    Solution solution;
    string out = solution.strWithout3a3b(A, B);
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
