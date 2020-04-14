#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    //647.cpp
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;
        vector<vector<bool>> isP(n, vector<bool>(n, true));
        int start = 0;
        int end = 0;
        int len = 0;
        int maxLen = 0;
        // j是字串起始位置，i是终止位置
        for (int i = 0;i < n;i++) {
            for (int j = 0; j <= i;j++) {
                if ( j == i) isP[i][j] = true;
                else if(i - j == 1) {
                    isP[i][j] = s[j] == s[i];
                } else if (i - j > 1) {
                    isP[i][j] = s[j]==s[i] && isP[i-1][j+1];
                }
                //if (s[j] == s[i] && (i - j <=2 || isP[j+1][i-1])) isP[j][i] = true;
                len = i - j + 1;
                if (isP[i][j] && len > maxLen) {
                    maxLen = len;
                    start = j;
                    end = i;
                }
            }
        }
        return s.substr(start, end - start + 1);
    }
};

int main(int argc, char* argv[]) {
    string A = "babad";
    /*
     *    b a b a d
     *  b T
     *  a F T
     *  b T F T
     *  a F T F T
     *  d F F F F T
     * */
    //string B = "cbbd";
    Solution solution;
    string out = solution.longestPalindrome(A);
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
