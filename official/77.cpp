#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> res;
        for (int i = 1; i <= n; i++) {
            res.push_back(i);
        }
        vector<int> out;
        vector<vector<int>> outs;
        //回溯法要初始化一个count计数器，count+1等于k时候return
        recall(0, 0, k, res, out, outs);
        return outs;
    }

    void recall(int t, int count, int& k, vector<int>& res, vector<int>& out, vector<vector<int>>& outs) {
        if (count == k) {
            outs.push_back(out);
            return;
        }

        for (int i = t; i < res.size(); i++) {
            out.push_back(res[i]);
            recall(i+1, count+1, k, res, out, outs);
            out.pop_back();
        }
    }
};

int main(int argc, char* argv[]) {
    int A = 4;
    int B = 2;
    
    Solution solution;
    vector<vector<int>> out = solution.combine(A, B);
    
    for (auto a:out) {
        cout << "#####" << endl;
        for (auto b:a) {
            cout << "out: " << b << endl;
        }
    }
    cout << "Congratulations!" << endl;
}
