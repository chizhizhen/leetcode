#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        string res(m+n, '0');
        for (int i = n-1; i >= 0;i--) {
            for (int j = m-1;j >= 0;j--) {
                int tmp = (res[i+j+1]-'0')+(num2[i]-'0')*(num1[j]-'0');
                int mod = tmp%10;
                int div = tmp/10;
                res[i+j+1] = mod + '0';
                res[i+j] += div;
            }
        }
        //去除首位'0'
        for (int i = 0; i < m+n;i++) {
            if (res[i] != '0') {
                return res.substr(i);
            }
        }
        return "0";
    }
};

int main(int argc, char* argv[]) {
    /*
     * index[i]*index[j]->index[i+j][i+j+1]
     *        1,2,3
     *          4,5
     *          1,5
     *        1,0
     *      0,5
     *        1,2
     *      0,8
     *    0,4
     *    */
    string A = "123";
    string B = "45";
    
    Solution solution;
    string out = solution.multiply(A, B);
    
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
