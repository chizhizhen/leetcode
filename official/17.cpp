#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> a{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> c;
        if (digits.empty()) return c;
        c.push_back(""); //size:0->1
        for (int i = 0;i < digits.size(); i++) {
            int res = digits[i]-'2';
            int len = c.size();
            for (int i = 0;i < len; i++)
            {
                for (auto m:a[res])
                {
                    c.push_back(c[i]+m);
                }
            }
            for(auto i :c) {
                cout << "before:" << i << endl;
            }
            c.erase(c.begin(), c.begin() + len);
            for(auto i :c) {
                cout << "after:" << i << endl;
            }
        }
        return c;
    }
};

int main(int argc, char* argv[]) {
    string A = "23";
    vector<string> B = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    Solution solution;
    vector<string> out = solution.letterCombinations(A);
    cout << "Congratulations!" << endl;
}
