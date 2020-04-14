#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <map>

using namespace std;

//1.A，B长度相同；
//2.若初始时A==B，A里必须有重复元素；

class Solution {
public:
    bool buddyStrings(string A, string B) { 
        if (A.size() != B.size()) return false;
        if (A == B && getNum(A) < A.size()) return true;
        vector<int> diff;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] != B[i]) diff.push_back(i);
        }
        return (diff.size() == 2 && A[diff[0]] == B[diff[1]] && A[diff[1]] == B[diff[0]]);
    }
private:
    int getNum(string A) {
        map<char, int> dict;
        int num = 0;
        for (auto i:A) {
            if (dict.find(i) == dict.end()) {
                dict[i] = 1;
                num += 1;
            }
        }
        return num;
    }
};

int main(int argc, char* argv[]) {
    string A = "aaaaaaabce";
    string B = "aaaaaaacbd";
    Solution solution;
    bool flag = solution.buddyStrings(A, B);
    cout << "out: " << flag << endl;
    cout << "Congratulations!" << endl;
}
