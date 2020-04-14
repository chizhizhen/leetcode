#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
public:
    TreeNode recoverFromPreorder(String S) {
        int[] index = new int[]{-1};
        return helper(S, index, 0);
    }
private:
    TreeNode helper(String s, int[] index, int depth) {
        int fast = index[0];
        if (fast + 1 >= s.length()) return null;
        while (fast + 1 < s.length() && s.charAt(fast + 1) == '-' ) fast++;
        int curDepth = fast - index[0];
        if (curDepth != depth) return null; //这是本题的关键， 如果深度不match， 则返回null。
        int n = 0;
        while (fast + 1 < s.length() && Character.isDigit(s.charAt(fast + 1))) {
            n *= 10;
            n += s.charAt(++fast) - '0';
        }
        TreeNode node = new TreeNode(n);
        index[0] = fast;
        node.left = helper(s, index, curDepth + 1);
        node.right = helper(s, index, curDepth + 1);
        return node;
    }
} */

int main(int argc, char* argv[]) {
    string s = "abcde";
    cout << s.size() << endl;
    for (auto b : s) {
        cout << b << endl;
    }
    
    int[] index = new int[]{-1};
    cout << index.size() << endl;

    cout << "Congratulations!" << endl;
    return 1;
}

