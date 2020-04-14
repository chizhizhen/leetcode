#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    //131.cpp
    vector<vector<string>> partition(string s) {
        vector<string> out;
        vector<vector<string>> res;
        backtrace(s, out, res);
        return res;
    }
    void backtrace(string s, vector<string>& out, vector<vector<string>>& res) {
        if (s == "") {
            res.push_back(out);
            return;
        }
        for (int i = 1; i <= s.size(); i++) {
            string sub = s.substr(0, i);
            if (isP(sub)) {
                out.push_back(sub);
                backtrace(s.substr(i, s.size()-i), out, res);
                out.pop_back();
            }
        }
    }
    bool isP(string s) {
        return s == string(s.rbegin(), s.rend());                            
    }
    //132.cpp
    int minCut(string s) {
        ;
    }
};
