#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    // 这个是我初始时写的回溯法，时间复杂度太高了；看答案才知道是个斐波那契数列,F(n)=F(n-1)+F(n-2)
    int climbStairs(int n) {
        int sum = 0;
        vector<vector<int>> out;
        vector<int> res;
        recall(n, sum, res, out);
        return out.size();
    }
    
    void recall(int n, int& sum, vector<int> res, vector<vector<int>>& out) {
        if (sum == n) {
            out.push_back(res);
        }

        if (sum < n) {
            for (int i = 0; i < _vec.size(); i++) {
                sum += _vec[i];
                res.push_back(_vec[i]);
                //cout << "sum: " << sum << endl;
                recall(n, sum, res, out);
                res.pop_back();
                sum -= _vec[i];
            }
        }
    }

    //动态规划思想，F(n) = F(n-1) + 1 或者F(n) = F(n-2) + 2
    int climbStairs2(int n) {
        if (n <= 2) return n;
        vector<int> res(n+1, 0);
        res[1] = 1;
        res[2] = 2;
        for (int i = 3; i <= n; i++) {
            res[i] = res[i-1] + res[i-2];
        }
        return res[n];
    }

private:
    vector<int> _vec = {1, 2};
};

int main(int argc, char* argv[]) {
    int A = 35;
    
    Solution solution;
    int out = solution.climbStairs(A);
    
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
