class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int depth = 0;
        int out = dfs(root, depth);
        return depth;
    }
    int dfs(TreeNode* root, int& depth) {
        if (root == NULL) return 0;
        int left = dfs(root->left, depth);
        int right = dfs(root->right, depth);
        depth = max(depth, left+right);
        return max(left, right) + 1;
    }
};
