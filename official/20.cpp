#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n%2 != 0) return false;
        if (n == 0) return true;
        //vector<char> tmp(0, '\0');
        vector<char> tmp;
        tmp.push_back(s[0]);
        for (int i = 1; i < s.size(); i++) {
            int j = tmp.size() - 1;
            if (tmp[j] == '(' && s[i] == ')') tmp.pop_back();
            else if (tmp[j] == '[' && s[i] == ']') tmp.pop_back();
            else if (tmp[j] == '{' && s[i] == '}') tmp.pop_back();
            else tmp.push_back(s[i]);
        }
        return tmp.size() == 0;
    }
};

int main(int argc, char* argv[]) {
    string s = "()[]{}";
    
    Solution solution;
    bool out = solution.isValid(s);
    
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
