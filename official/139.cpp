#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.size();
        //if (size == 0) return true;
        vector<bool> res(size+1);
        res[0] = true;
        for (int i = 1; i <= size; i++) {
            for (int j = 0; j < i; j++) {
                if (res[j] == true && findWord(wordDict, s.substr(j, i-j))) {
                    res[i] = true;
                    break;
                }
            }
        }
        for (auto i:res) {
            cout << i << endl;
       }
        return res[size];
    }

    //139.cpp
    bool workBreakDP(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, 0);
        dp[0] = 1;
        for (int i = 0; i <= n; i++) {
            for (auto &w:wordDict) {
                int m = w.size();
                if (i >= m) {
                    if (s.compare(m, i-m, w) == 0 && dp[i-m] == 1) {
                        dp[i] = 1;
                    }
                }
            }
        }
        return dp[n];
    }

private:
    bool findWord(vector<string> dicts, string str) {
        bool flag = false;
        for (auto c:dicts) {
            if (str == c) {
                flag = true;
                break;
            }
        }
        return flag;
    }
};

int main(int argc, char* argv[]) {
    string s = "applepenapple";
    vector<string> wordDict = {"apple", "pen"};
    Solution solution;
    bool out = solution.wordBreak(s, wordDict);
    
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
