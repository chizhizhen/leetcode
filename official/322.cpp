#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> out;
        vector<vector<int>> res;
        backtrace(coins, amount, out, res);
        sort(res.begin(), res.end(), [](vector<int>& v1, vector<int>& v2) -> bool {return(v1.size() < v2.size());});
        return res[0].size();
    }
    void backtrace(vector<int>& coins, int amount, vector<int>& out, vector<vector<int>>& res) {
        if (getNum(out) == amount) {
            res.push_back(out);
            return;
        }
        for (int i = 0; i < coins.size(); i++) {
            out.push_back(coins[i]);
            backtrace(coins, amount, out, res);
            out.pop_back();
        }
    }
    int getNum(vector<int> nums) {
        int num = 0;
        for (auto i:nums) num += i;
        return num;
    }
};

bool cmp(const vector<int> &a, const vector<int> &b) {
    return a.size() < b.size();
}

int main(int argc, char* argv[]) {
    /*
    vector<vector<int>> A = {{1,3,5,6},{5},{1,2},{3,4,5}};
    cout << A[0].size() << endl;
    sort(A.begin(), A.end(), [](vector<int> v1, vector<int> v2) -> bool {return (v1.size()<v2.size());});
    //sort(A.begin(), A.end(), cmp);
    cout << A[0].size() << endl;
    */
    vector<int> A = {1,2,5};
    int B = 11;
    Solution solution;
    int out = solution.getNum(A);
    //int out = solution.coinChange(A, B);
    cout << "out: " << out << endl;
}
