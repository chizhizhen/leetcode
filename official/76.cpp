#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() == 0) return "";
        int size = s.size();
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                string str = s.substr(i, j - i + 1);
                if (isIn(str, t)) _dict[j-i] = str;
            }
        }
        map<int, string>::iterator iter = _dict.begin();
        return iter->second;
    }
private:
    map<int, string> _dict;
    bool isIn(string A, string B) {
        vector<char> str_a;
        vector<char> str_b;
        for (char a:A) {
            str_a.emplace_back(a);
        }
        for (char b:B) {
            str_b.emplace_back(b);
        }
        return isIn(str_a, str_b);
    }

    bool isIn(vector<char> A, vector<char> B) {
        bool flag = true;
        for (char b:B) {
            if (!isIn(A, b)) return false;
        }
        return flag;
    }

    bool isIn(vector<char> A, char b) {
        bool flag = false;
        for (char a:A) {
            if (a == b) return true;
        }
        return flag;
    }
};

int main(int argc, char* argv[]) {
    string S = "ADOBECODEBANC";
    string T = "ABC";

    Solution solution;
    string out = solution.minWindow(S, T);
    
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
