#include <iostream>
#include <vector>

using namespace std;

struct BinaryTree {
    int val;
    BinaryTree* left;
    BinaryTree* right;
    BinaryTree(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isCousins(BinaryTree* root, int x, int y) {
        dfs(root, NULL, 0);
        return _depth[x] == _depth[y] && _parent[x] != _parent[y];
    }

    void dfs(BinaryTree* node, BinaryTree* parent, int depth) {
        if (parent == NULL) return; 
        int val = root->val;
        _depth[val] = depth;
        _parent[val] = parent;
        dfs(root->left, root, depth + 1);
        dfs(root->right, root, depth + 1);
    }

private:
    unordered_map<int, int> _depth; 
    unordered_map<int, BinaryTree*> _parent; 
}
