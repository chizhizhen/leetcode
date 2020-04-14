#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int getValue(vector<int> A) {
        for (int i = 1;i < A.size(); i++) {
            if (A[i]>A[i-1] && A[i]>A[i+1]) {
                return i;
            }
        }
        return A.size();
    }
};

int main(int argc, char* argv[]) {
    vector<int> A = {0,2,4,5,3,1,0};
    Solution solution;
    int out = solution.getValue(A);
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
