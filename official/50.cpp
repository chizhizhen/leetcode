#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == -1) return 1/x;
        double tmp = myPow(x, n/2);
        return tmp * tmp * myPow(x, n%2);
    };
};

int main(int argc, char* argv[]) {
    double A = 0.44894;
    int B = -5;
    Solution solution;
    double out = solution.myPow(A, B);
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
