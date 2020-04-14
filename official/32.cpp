#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> res(n, 0);
        int out = 0;
        
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    res[i] = 2 + (i >= 2?res[i-2]:0);
                }
                else if (i-res[i-1]-1 >= 0 && s[i-res[i-1]-1] == '(') {
                    if (i - res[i-1] - 2 >= 0) {
                        res[i] = 2 + res[i-1] + res[i-res[i-1]-2];
                    } else {
                        res[i] = 2 + res[i-1];
                    }
                }
            }
            cout << "index: " << i << ", res: " << res[i] << endl;
            out = max(out, res[i]);
        }
        return out;
    }
private:
    int max(int x, int y) {
        return x > y? x:y;
    }
};

int main(int argc, char* argv[]) {
    string s = "(()(())";
    
    Solution solution;
    int out = solution.longestValidParentheses(s);
    
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
