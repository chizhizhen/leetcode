#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long out;
        vector<int> res;
        int flag = x < 0? -1:1;
        x = flag * x;
        int num = 0;
        while(x / 10) {
            res.push_back(x % 10);
            x = x/10;
            num += 1;
        }
        res.push_back(x);
        for (int i = num + 1, j = 0; i > 0; i--, j++) {
            cout << i << ", " << j << endl;
            out += pow(10, i-1) * res[j];
        }
        return out*flag;
    }
};

int main(int argc, char* argv[]) {
    int A = 321;
    int B = 120;
    int C = -123;
    Solution solution;
    int out = solution.reverse(123);
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
