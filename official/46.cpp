#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(nums, res, 0);
        return res;
    }
    void dfs(vector<int>& nums, vector<vector<int>>& res, int val) {
        if (val == nums.size()) {
            res.push_back(nums);
        }
        for (int i = val; i < nums.size(); i++) {
            swap(nums[i], nums[val]);
            dfs(nums, res, val+1);
            swap(nums[i], nums[val]);
        }
    }
private:
    void swap(int& x, int& y) {
        int tmp = x;
        x = y;
        y = tmp;
    }
    string _toStr(vector<int> vals) {
        string s;
        for (auto i:vals) {
            s += to_string(i);
        }
        return s;
    }
    string _toStr(vector<vector<int>> vals) {
        string s;
        for (auto i:vals) {
            for (auto j:i) {
                s += to_string(j);
            }
        }
        return s;
    }
};

int main(int argc, char* argv[]) {
    vector<int> A = {1, 2, 3};
    //vector<int> A = {1, 2};
    Solution solution;
    vector<vector<int>> out = solution.permute(A);
    for (auto i:out) {
        cout << "list:" << endl;
        for (auto j:i) {
            cout << "out: " << j << endl;
        }
    }
    cout << "Congratulations!" << endl;
}
