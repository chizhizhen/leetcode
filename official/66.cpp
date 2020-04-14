#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i] += 1;
                break;
            }
        }
        if (digits[0] == 0) {
            digits.push_back(0);
            digits[0] = 1;
        }
        return digits;
    }
};

int main(int argc, char* argv[]) {
    vector<int> A = {1,2,3};
    
    Solution solution;
    vector<int> out = solution.plusOne(A);
    
    for (auto a:out) {
        cout << "out: " << a << endl;
    }
    cout << "Congratulations!" << endl;
}
