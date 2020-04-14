class Solution {
public:
    //递归
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        backtrace(res, root);
        return res;
    }
    void backtrace(vector<int>& res, TreeNode* root) {
        if (root == NULL) return;
        if (root->left) backtrace(res, root->left);
        res.push_back(root->val);
        if (root->right) backtrace(res, root->right);
    }
    //迭代
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> sk;
        while(root || sk.size()) {
            while(root) {
                sk.push(root);
                root = root->left;
            }
            root = sk.top();
            sk.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};
