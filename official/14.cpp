#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string min_str;
        int num = INT_MAX;
        for (auto str:strs) {
            int n = getNum(str);
            if (n <= num) {
                num = n;
                min_str = str;
            }
        }
        cout << "min str: " << min_str << endl;
        string out = "";
        for (int i = 0; i < min_str.size();i++) {
            char s = min_str[i];
            for (int j = 0; j < strs.size(); j++) {
                if (strs[j][i] != s) return out;
            }
            out.push_back(s);
        }
        return out;
    }
private:
    int getNum(string s) {
        int num = 0;
        for (auto i:s) {
            num += 1;
        }
        return num;
    }
    bool isInside(string s, char a) {
        for (auto i:s) {
            if (i == a) return true;
        }
        return false;
    }
    bool isInside(vector<string> s, char a, int k) {
        int num = 0;
        for (auto i:s) {
            if (isInside(i, a)) num += 1;
        }
        if (num == s.size()) return true;
        else return false;
    }
};

int main(int argc, char* argv[]) {
    vector<string> A = {"flower","flow","flight"};
    //vector<string> A = {"ab","aa"};
    Solution solution;
    string out = solution.longestCommonPrefix(A);
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
