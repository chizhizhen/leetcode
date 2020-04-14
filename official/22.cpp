#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        backtrace(0, 0, n, s, res);
        return res;
    }
    void backtrace(int left, int right, int n, string& s, vector<string>& res) {
        if (left == n && right == n) {
            res.push_back(s);
        }
        if (left < n) {
            s += '(';
            backtrace(left+1, right, n, s, res);
            s.pop_back();
        }
        if (right < left) {
            s += ')';
            backtrace(left, right+1, n, s, res);
            s.pop_back();
        }
    }
};

int main(int argc, char* argv[]) {
    int A = 3;
    
    Solution solution;
    vector<string> out = solution.generateParenthesis(A);
    for (auto str:out)  {   
        cout << "out: " << str << endl;
    }
    cout << "Congratulations!" << endl;
}
