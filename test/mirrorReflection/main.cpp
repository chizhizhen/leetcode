#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int lcm = p * q / minCommonMultiple(p, q);
        int x = lcm / p, y = lcm / q;
        if (y % 2 == 1) {
            if (x % 2 == 1)
                return 1;
            return 0;
        }
        return 2;
    }
private:
    //GCD -  greatest common divisor  最大公因数
    int maxCommonDivisor(int x, int y) {
        if(x && y) {
            while( (x %= y) && (y %= x));
        }
        return x + y;
    }
    //LCM - least common multiple 最小公倍数
    int minCommonMultiple(int x, int y) {
        cout << "1: " << maxCommonDivisor(x, y) << endl;
        cout << "2: " << x*y/maxCommonDivisor(x, y) << endl;
        return x*y/maxCommonDivisor(x, y);
    }
};

int main(int argc, char* argv[]) {
    int A = atoi(argv[1]);
    int B = atoi(argv[2]);
    Solution solution;
    int out = solution.mirrorReflection(A, B);
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
