#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int mod = k%n;
        vector<int> res = nums;
        for (int i = 0; i < n; i++) {
            if (i < mod) {
                nums[i] = res[n-mod+i];
            } else {
                nums[i] = res[i-mod];
            }
        }
    }
};

int main(int argc, char* argv[]) {
    //vector<int> A = {1,2,3,4,5,6,7};
    //int B = 3;
    vector<int> A = {-1,-100,3,99};
    int B = 2;
    
    Solution solution;
    solution.rotate(A, B);
    for (auto a:A) {
        cout << a << endl;
    }
    cout << "Congratulations!" << endl;
    return 1;
}
