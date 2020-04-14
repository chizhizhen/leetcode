#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        int l = 0;
        int r = x - 1;
        while (l < r) {
            long m = (l + r) / 2;
            if (m * m <= x && (m+1)*(m+1) > x) {
                return m;
            }
            if (m * m > x) r = m - 1;
            else if (m * m < x) l = m + 1;
        }
        return l;
    }
};

int main(int argc, char* argv[]) {
    int A = atoi(argv[1]);
    
    Solution solution;
    int out = solution.mySqrt(A);
    
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
