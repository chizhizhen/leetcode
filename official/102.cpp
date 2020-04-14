class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> out;
        int count = 0;
        dfs(root, count, out);
        return out;
    }
    void dfs(TreeNode* root, int& count, vector<vector<int>>& out) {
        if (root == NULL) return;
        if (count == out.size()) out.emplace_back();
        if (root->val) out[count].push_back(root->val);
        dfs(root->left, count+1, out);
        dfs(root->right, count+1, out);
    }
};
