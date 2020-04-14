#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

struct BinaryTreeNode {
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

class Solution {
public:
    int getValue(BinaryTreeNode* A) {
        int out = 0;
        dfs(A, out);
        return out;
    }
    
    void dfs(BinaryTreeNode* A, int out) {
        if (A == NULL) return 0;
        int left_value = dfs(A->left, out);
        int right_value = dfs(A->right, out);
        out += (abs(left_value)) + (abs(right_value));

        return A->val + left_value + right_value - 1;
    }
};
