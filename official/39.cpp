#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> out;
        for (int i = 0; i < n; i++) {
            int div = target/candidates[i];
            int mod = target%candidates[i];
            vector<int> res;
            if (mod == 0) {
                for (int j = 0;j < div;j++) {
                    res.push_back(candidates[i]);
                }
            }
            else if (findCand(candidates, mod)) {
                res.push_back(mod);
                for (int j = 0;j < div;j++) {
                    res.push_back(candidates[i]);
                }
            }
            out.push_back(res);
        }
        return out;
    }
    
    // THIS IS RIGHT!
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
            recall(ind, cands, T-cands[i], res, out);
            res.pop_back();
        }
    }
        
private:
    bool findCand(vector<int> A, int y) {
        bool flag = false;
        for (auto a:A) {
            if (a == y) {
                flag = true;
                break;
            }
        }
        return flag;
    }
};

int main(int argc, char* argv[]) {
    vector<int> A = {2,3,5};
    int B = 8;

    Solution solution;
    vector<vector<int>> out = solution.combinationSum2(A, B);
    
    for (int i = 0; i < out.size(); i++) {
        cout << "#####" << endl;
        for (int j = 0; j < out[i].size(); j++) {
            cout << out[i][j] << endl;
        }
    }
    cout << "Congratulations!" << endl;
}
