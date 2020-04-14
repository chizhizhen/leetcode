#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int getValue(vector<int> A) {
        sort(A.begin(), A.end());
        for (int i = A.size();i >= 2; i--) {
            if (A[i-2] + A[i-1] > A[i]) {
                return A[i-2] + A[i-1] + A[i];
            }
        }
        return 0;
    }
};

int main(int argc, char* argv[]) {
    vector<int> A = {3,6,2,3};
    Solution solution;
    int out = solution.getValue(A);
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
