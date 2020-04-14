#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        if (n == 0) return 0;
        /* 去掉字符串前后空格
        int l = 0;
        int r = n - 1;
        while (l < r) {
            if (s[l] == ' ') l++;
            if (s[r] == ' ') r--;
            if (s[l] != ' ' && s[r] != ' ') break;
        }
        string str = s.substr(l, r+1); */
        bool flag = false;
        int ind = 0;
        for (int i = s.size()-1;i >= 0; i--) {
            if (s[i] != ' ') {
                flag = true;
                ind = i;
                break;
            }
        }
        
        int out = 0;
        if (flag) {
            for (int i = ind; i >= 0;i--) {
                if (s[i] != ' ') out++;
                else break;
            }
        }

        return out;
    }
};

int main(int argc, char* argv[]) {
    //string s = "Hello World";
    string s = argv[1];
    
    Solution solution;
    int out = solution.lengthOfLastWord(s);
    
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
