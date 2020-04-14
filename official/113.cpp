#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        vector<vector<int>> out;
        vector<int> res;
        dfs(root, sum, 0, res, out);
        return out;
    }
    void dfs(TreeNode* root, int& sum, int cur, vector<int>& res, vector<vector<int>>& out) {
        if (root == NULL) return;
        res.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (cur+root->val == sum) {
                out.push_back(res);
            }
        }
        dfs(root->left, sum, cur+root->val, res, out);
        dfs(root->right, sum, cur+root->val, res, out);
        res.pop_back();
    }
};
