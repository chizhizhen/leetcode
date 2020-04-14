#include <iostream>
#include <vector>

class Solution {
public:
    map<int, vector< pair<int, int> > > memo;
    void dfs(TreeNode* root, int x, int y) {
        if (root == NULL) return;
        memo[x].push_back({y, root->val});
        dfs(root->left, x - 1, y + 1);
        dfs(root->right, x + 1, y + 1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int> > res;
        for (auto& p : memo) {
            sort(p.second.begin(), p.second.end());
            vector<int> v;
            for (auto t : p.second) {
                v.push_back(t.second);
            }
            res.push_back(v);
        }
        return res;
    }
};
