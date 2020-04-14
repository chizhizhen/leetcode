#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}

class Solution {
public:
    string getValue(TreeNode* root) {
        vector<string> res;
        dfs(root, "", res);
        sort(res.begin(), res.end());
        return res[0];
    }

    void dfs(TreeNode* root, string path, vector<string>& res) {
        if (root->left) {
            path = char('a' + root->val) + path;
            dfs(TreeNode* root->left, path, res);
        }
        if (root->right) {
            path = char('a' + root->val) + path;
            dfs(TreeNode* root->right, path, res);
        }
        if (!root->left && !root->right) {
            res.push_back(char('a'+root->val) + path);
            return;
        }
    }

private:
    int _fa[26];

    void init() {
        for (int i = 0; i < _fa.size(); i++) {
            _fa[i] = i;
        }
    }
};
