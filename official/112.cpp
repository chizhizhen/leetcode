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
        bool flag = false;
        dfs(root, 0, sum, flag);
        return flag;
    }
    void dfs(TreeNode* root, int cur, int& sum, bool& flag) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            //注意这里要加上当前节点值
            if (cur+root->val == sum) {
                flag = true;
                return;
            }
        }
        dfs(root->left, cur+root->val, sum, flag);
        dfs(root->right, cur+root->val, sum, flag);
    }
};
