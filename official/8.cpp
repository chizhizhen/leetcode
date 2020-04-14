#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        long res = 0;
        int k = 0;
        int flag = 1;
        while (k < str.size()) {
            if (str[k] != ' ') break;
            k++;
        }
        if (str[k] == '-') {
            flag = -1;
        }
        
        if (str[k] == '+' || str[k] == '-') k++;
        
        cout << k << endl;
        cout << str[k] << endl;
        if (!isdigit(str[k])) return 0;

        for (int i = k; i < str.size(); i++) {
            if (str[i] == ' ' || str[i] == '.') break;
            int k = str[i] - '0';
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && k > 7)) { 
                return flag > 0 ? INT_MAX : INT_MIN;
            }
            res = res* 10 +k;
        }

        return res*flag;
    }
};

int main(int argc, char* argv[]) {
    string A = "4193 with words";
    string B = "42";
    string C = "    -42";
    string D = "words and 987";
    Solution solution;
    int out = solution.myAtoi(D);
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
