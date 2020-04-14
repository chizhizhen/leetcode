#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size() - 1;
        int n = b.size() - 1;
        string str;
        int k = 0;
        int sum = 0;
        while (m >= 0 || n >= 0) {
            int p = 0;
            if (m >= 0) {
                p = a[m] - '0';
                m--;
            }
            int q = 0;
            if (n >= 0) {
                q = b[n] - '0';
                n--;
            }

            sum = p + q + k;
            str = to_string(sum % 2) + str;
            k = sum/2;
        }
        if (k == 1) {
            str = '1' + str;
        }
        return str;
    }
};

int main(int argc, char* argv[]) {
    string A = "1010";
    string B = "1011";
    
    Solution solution;
    string out = solution.addBinary(A, B);
    
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
