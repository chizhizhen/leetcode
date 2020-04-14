#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int getValue(vector<int> A) {
        vector<int> up(A.size(), 1);
        vector<int> dw(A.size(), 1);
        int out = 0;
        for (int i = 1; i < A.size(); i++) {
            if (A[i] > A[i-1]) up[i] = dw[i-1] + 1;
            if (A[i] < A[i-1]) dw[i] = up[i-1] + 1;
            out = max(out, up[i], dw[i]); 
            cout << "ind: " << i << ", " << "out: " << out << endl;
        }
        return out;
    }
private:
    int max(int x, int y) {
        return x > y? x:y;
    }
    int max(int x, int y, int z) {
        return max(x, max(y, z));
    }
};

int main(int argc, char* argv[]) {
    vector<int> A = {9,4,2,10,7,8,8,1,9};
    Solution solution;
    int out = solution.getValue(A);
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
