#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(vector<int> A, vector<int> B) {
        vector<int> out;
        int n = A.size();
        preorder(0, 0, n-1, A, B, out);
        return out;
    }
    void preorder(int root, int left, int right, vector<int> A, vector<int> B, vector<int>& out) {
        if (left>right) return;
        int val = A[root];
        int i = left;
        while(i < right && B[i] != val) i++; //定位根在中序的位置
        preorder(root+1, left, i-1, A, B, out); //递归处理左子树
        preorder(root+i-left+1, i+1, right, A, B, out); //递归处理右子树
        out.push_back(B[i]);
    }

    //Leetcode105/106
    vector<int> buildTree(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int ind = 0;
        vector<int> out;
        buildTree(ind, A, B, out, 0, n-1);
        return out;
    }
    void buildTree(int& ind, vector<int>& A, vector<int>& B, vector<int>& out, int left, int right) {
        if (ind >= A.size()) return;
        int val = A[ind];
        int i = left;
        for (;i <= right; i++) {
            if (B[i] == val) break;
        }
        if (left < i) buildTree(++ind, A, B, out, left, i-1);
        if (i < right) buildTree(++ind, A, B, out, i+1, right);
        out.push_back(B[i]);
    }
};

int main(int argc, char* argv[]) {
    vector<int> A = {1,2,4,7,3,5,8,9,6};
    vector<int> B = {4,7,2,1,8,5,9,3,6};
    Solution solution;
    //vector<int> out = solution.preorderTraversal(A, B);
    vector<int> out = solution.buildTree(A, B);
    for (auto a:out) {
        cout << "out: " << a << endl;
    }
    cout << "Congratulations!" << endl;
}
