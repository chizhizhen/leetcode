#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return nums;
        vector<int> out;
        for (int i = 0; i < n; i++) {
            int index = (nums[i] - 1) % n;
            nums[index] = nums[index] + n;
            //cout << nums[i] << "==>" << i << "==>" << index << "==>" << index+n << endl;
            //nums[index] = index + n;
        }

        for (auto num:nums) {
            cout << "===" << num << endl;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] <= n) {
                out.push_back(i+1);;
            }
        }
        return out;
    }
};

int main(int argc, char* argv[]) {
    vector<int> A = {4,3,2,7,8,2,3,1};
    
    Solution solution;
    vector<int> out = solution.findDisappearedNumbers(A);
    for (auto o:out) {
        cout << "out: " << o << endl;
    }
    cout << "Congratulations!" << endl;
}
