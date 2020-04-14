#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    vector<int> getValue1(vector<int> A) {
        for (int i = 0, j = 0; j < A.size(); j++) {
            if (isEven(A[j])) swap(A[i++], A[j]);
        }
        return A;
    }
    
    vector<int> getValue1_new(vector<int> A) {
        int l = 0;
        int r = A.size() -1;
        while (l < r) {
            if (!isEven(A[l] && isEven(A[r]))) {
                swap(A[l], A[r]);
            }
            if (isEven(A[l])) l++;
            if (!isEven(A[r])) r--;
        }
        return A;
    }
    
    vector<int> getValue2(vector<int> A) {
        int odd = 1;
        int even = 0;
        while(odd < A.size() && even < A.size()) {
            if (!isEven(A[even]) && isEven(A[odd])) {
                swap(A[odd], A[even]);
            }
            if (isEven(A[even])) even += 2;
            if (!isEven(A[odd])) odd += 2;
        }
        return A;
    }

private:
    bool isEven(int x) {
        if (x%2 == 0) return true;
        return false;
    }
};

int main(int argc, char* argv[]) {
    //vector<int> A = {3,1,2,4};
    vector<int> A = {4,2,5,7};
    Solution solution;
    //vector<int> out = solution.getValue1(A);
    //vector<int> out = solution.getValue1_new(A);
    vector<int> out = solution.getValue2(A);
    for (auto i:out) {
        cout << "out: " << i << endl;
    }
    cout << "Congratulations!" << endl;
}
