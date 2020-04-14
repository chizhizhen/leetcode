#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }
    bool isValid(TreeNode* root, int LONG_MIN, int LONG_MAX) {
        if (root ==  NULL) return true;
        int val = root->val;
        if (val <= LONG_MIN || val >= LONG_MAX) return false;
        return isValid(root->left, LONG_MIN, val) && isValid(root->right, val, LONG_MAX);
    }
};
