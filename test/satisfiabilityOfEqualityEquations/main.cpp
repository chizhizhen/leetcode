#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool equationsPossible(vector<string> input) {
        init_fa();
        //print_fa();
        //构建无向图，如果相等，节点间有连接;
        for (string& s : input) {
            if (s[1] == '=') {
                u(s[0] - 'a', s[3] - 'a');
            }
        }
        print_fa();
        
        for (string& s : input) {
            if (s[1] == '!') {
                if (f(s[0] - 'a') == f(s[3] - 'a')) 
                //如果能找到相等，证明俩节点有连接，不等式就不成立
                    return false;
            }
        }
        
        return 1;
    }

private:
    //vector<int> _fa(26, 0);
    int _fa[26];

    void init_fa() {
        for (int i = 0; i < 26; ++i) {
            _fa[i] = i;
        }
    }

    void print_fa() {
        for (auto i : _fa) {
            cout << "[" << i << "]" << endl;
        }
    }

    void u(int a, int b) {
        int pa = f(a);
        int pb = f(b);
        _fa[pa] = pb;
    }

    int f(int x) {
        if (_fa[x] == x) return x;
        cout << "### " << x << " " << _fa[x] << endl;
        return _fa[x] = f(_fa[x]);
    }
};

int main(int argc, char* argv[]) {
    vector<string> input = {"a==b", "c==e", "v==w", "b==h"};
    Solution solution;
    bool out = solution.equationsPossible(input);
    cout << "output: " << out << endl;
    cout << "Congratulations!" << endl;
}
