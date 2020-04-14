#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> out;
        vector<vector<int>> res(1, vector<int>(0, 0));
        for (int i = 1; i <= nums.size();i++) {
            recall(0, 0, i, nums, out, res);
        }
        return res;
    }

    void recall(int t, int count, int k, vector<int>& nums, vector<int>& out, vector<vector<int>>& res) {
        if (count == k) {
            res.push_back(out);
            return;
        }
        for (int i = t; i < nums.size(); i++) {
            out.push_back(nums[i]);
            recall(i+1, count+1, k, nums, out, res);
            out.pop_back();
        }
    }
};

int main(int argc, char* argv[]) {
    vector<int> A = {1,2,3};
   
    Solution solution;
    vector<vector<int>> out = solution.subsets(A);
    
    for (auto a:out) {
        cout << "#####" << endl;
        for (auto b:a) {
            cout << "out: " << b << endl;
        }
    }
    cout << "Congratulations!" << endl;
}
