#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
    }
};

int main(int argc, char* argv[]) {
    string s = "()[]{}";
    
    Solution solution;
    bool out = solution.isValid(s);
    
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
