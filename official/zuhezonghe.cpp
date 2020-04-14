#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //39.cpp
    vector<vector<int>> combinationSum1(vector<int>& candidates, int target) {
        vector<vector<int>> out;
        vector<int> res;
        recall(0, candidates, target, res, out);
        return out;
    }
    void recall(int ind, vector<int> cands, int T, vector<int>& res, vector<vector<int>>& out) {
        //if (T < 0) return;
        //else if (T == 0) out.push_back(res);
        if (T <= 0) {
            if (T == 0) {
                out.push_back(res);
            }
            return;
        }

        for (int i = ind; i < cands.size();i++) {
            res.push_back(cands[i]);
            recall(i, cands, T-cands[i], res, out);
            res.pop_back();
        }
    }
    
    //40.cpp
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> res;
        vector<vector<int>> out;
        dfs(0, target, candidates, res, out);
        return out;
    }
    void dfs(int ind, int target, vector<int>& cands, vector<int>& res, vector<vector<int>>& out) {
        if (target <= 0) {
            if (target == 0) {
                out.push_back(res);
            }
            return;
        }
        if (ind == cands.size()) {
            return;
        }
        for (int i = ind; i < cands.size(); i++) {
            if (i > ind && cands[i] == cands[i-1]) continue;
            res.push_back(cands[i]);
            dfs(i+1, target - cands[i], cands, res, out);
            res.pop_back();
        }
    }

    //216.cpp
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> cands = {1,2,3,4,5,6,7,8,9};
        vector<int> res;
        vector<vector<int>> out;
        dfs(0, k, n, cands, res, out);
        return out;
    }
    void dfs(int ind, int k, int n, vector<int>& cands, vector<int>& res, vector<vector<int>>& out) {
        if (res.size() == k && n == 0) {
            out.push_back(res);
            return;
        }
        for (int i = ind; i < cands.size() && i <= n; i++) {
            res.push_back(cands[i]);
            dfs(i+1, k, n - cands[i], cands, res, out);
            res.pop_back();
        }
    }
    
    //377.cpp
    vector<vector<int>> combinationSum4(vector<int>& nums, int target) {
        vector<int> res;
        vector<vector<int>> out;
        dfs(0, nums, target, res, out);
        //return out.size();
        return out;
    }
    void dfs(int ind, vector<int>& nums, int target, vector<int>& res, vector<vector<int>>& out) {
        if (target == 0) {
            out.push_back(res);
            return;
        }
        for (int i = ind; i < nums.size() && target >= nums[i]; i++) {
            res.push_back(nums[i]);
            dfs(0, nums, target - nums[i], res, out);
            res.pop_back();
        }
    }
};

int main(int argc, char* argv[]) {
    vector<int> A = {10,1,2,7,6,1,5};
    int B = 8;
    Solution solution;
    //vector<vector<int>> out = solution.combinationSum2(A, B);
    //vector<vector<int>> out = solution.combinationSum3(2, 6);
    vector<int> C = {1,2,3};
    int D = 4;
    vector<vector<int>> out = solution.combinationSum4(C, D);
    for (auto& a:out) {
        cout << "..." << endl;
        for (auto& b:a) {
            cout << b << endl;
        }
    }
    return 1;
}
