#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> res;
        int flag = x < 0? -1:1;
        while (x/10) {
            res.push_back(x%10);
            x = x/10;
        }
        res.push_back(x);
        if (flag == -1) return false;
        else return isP(res);
    }
private:
    bool isP(vector<int> x) {
        int num = x.size();
        for (int i = 0; i < num; i++) {
            if (x[i] != x[num-i-1]) return false;
        }
        return true;
    }
};

int main(int argc, char* argv[]) {
    int A = atoi(argv[1]); //121
    Solution solution;
    bool out = solution.isPalindrome(A);
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
