struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        res = backtrace(1, n);
        return res;
    }
    vector<TreeNode*> backtrace(int l, int r) {
        vector<TreeNode*> out;
        vector<TreeNode*> left;
        vector<TreeNode*> right;

        for (int i = l; i <= r; i++) {
            vector<TreeNode*> left = backtrace(l, i-1);
            vector<TreeNode*> right = backtrace(i+1, r);
            if (left.size() == 0) left.push_back(NULL);
            if (right.size() == 0) right.push_back(NULL);

            for (int k = 0; k < left.size(); k++) {
                for (int j = 0; j < right.size(); j++) {
                    TreeNode* curr = new TreeNode(i);
                    curr->left = left[k];
                    curr->right = right[j];
                    out.push_back(curr);
                }
            }
        }
        return out;
    }
};
