#include<iostream>
#include<vector>

using namespace std;

//F[i][j]:前i件中若干个物品放入体积为j的背包中的最大价值。

class Solution {
public:
    int getValue(vector<int> nweight, vector<int> nvalues, int W) {
        //vector<vector<int>> out = {{0}};
        int nobjs = nweight.size();
        vector<vector<int>> out(nobjs, vector<int>(W+1, 0));
        for (int i = 1; i < nobjs; i++) {
            for (int j = 1;j <= W; j++) {
                if (j < nweight[i]) {
                    out[i][j] = out[i-1][j];
                } else {
                    out[i][j] = max(out[i-1][j], out[i-1][j-nweight[i]]+nvalues[i]);
                }
                cout << out[i][j] << ' ';
            }
            cout << endl;
        }
        return out[nobjs-1][W-1];
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<int> nvalues = {0, 2, 5, 3, 10, 4};
    vector<int> nweight = {0, 1, 3, 2, 6, 2};
    int W = 12;
    int out = solution.getValue(nweight, nvalues, W);
    cout << "Final output: " << out << endl;
    cout << "Congratulations!" << endl;
}
