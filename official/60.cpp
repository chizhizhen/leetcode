#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<string> nums;
        for (int i = 1; i <= n;i++) {
            nums.emplace_back(to_string(i));
        }
        vector<vector<string>> out = getPermutation(nums);
    
        string res;
        for (int i = 0; i < n;i++) {
            res += out[k-1][i];
        }
        return res;
    }
    
    vector<vector<string>> getPermutation(vector<string> nums) {
        vector<vector<string>> strs;
        recall(0, nums, strs);
        return strs;
    }

    void recall(int T, vector<string>& nums, vector<vector<string>>& strs) {
        if (T == nums.size()) {
            strs.push_back(nums);
        }

        for (int i = T; i < nums.size(); i++) {
            swap(nums[i], nums[T]);
            recall(T+1, nums, strs);
            swap(nums[i], nums[T]);
        }
    }
};

int main(int argc, char* argv[]) {
    int A = 4;
    int B = 9;

    Solution solution;
    string out = solution.getPermutation(A, B);
    
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
