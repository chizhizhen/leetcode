class Solution {
public:
    //递归，就是回溯的一种
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        backtrace(root, res);
        return res;
    }
    void backtrace(TreeNode* node, vector<int>& res) {
        if (node != NULL) {
            int val = node->val;
            res.push_back(val);
        } else {
            return;
        }
        backtrace(node->left, res);
        backtrace(node->right, res);
    }
    //迭代，利用栈思想
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> sk;
        while(root||sk.size()) {
            while(root) {
                sk.push(root);
                res.push_back(root->val);
                root = root->left;
            }
            root = sk.top();
            sk.pop();
            root = root->right;
        }
        return res;
    }
};
