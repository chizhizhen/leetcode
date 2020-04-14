#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) return {{1}};
        if (numRows == 2) return {{1},{1,1}};
        vector<vector<int>> out = {{1},{1,1}};
        for (int i = 2; i < numRows; i++) {
            vector<int> res;
            res.push_back(1);
            for (int j = 1; j < i; j++) {
                res.push_back(out[i-1][j-1]+out[i-1][j]);
            }
            res.push_back(1);
            out.push_back(res);
        }
        return out;
    }
};

int main(int argc, char* argv[]) {
    int A = atoi(argv[1]);
    
    Solution solution;
    vector<vector<int>> out = solution.generate(A);
   
    for (auto a:out) {
        cout << "===" << endl; 
        for (auto b:a) {
            cout << "out: " << b << endl;
        }
    }
    cout << "Congratulations!" << endl;
}
