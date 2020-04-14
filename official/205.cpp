#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sd;
        unordered_map<char, char> td;
        for (int i = 0; i < s.size(); i++) {
            char x = s[i];
            char y = t[i];
            if (sd.count(x)) {
                if (sd[x] != y) return false;
            } else if (td.count(y)) {
                if (td[y] != x) return false;
            } else {
                sd[x] = y;
                td[y] = x;
            }
        }
        return true;
    }
};

int main(int argc, char* argv[]) {
    string A = "egg";
    string B = "abb";

    Solution solution;
    bool out = solution.isIsomorphic(A, B);
    
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
