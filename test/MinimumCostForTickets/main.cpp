#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int getValue(vector<int> days, vector<int> costs) {
        vector<int> dp(366, 0);
        for (auto i: days) {
            dp[i] = 1;
        }
    
        for (int i = 1; i < 366; i++) {
            if (dp[i] == 0) {
                dp[i] = dp[i-1];
            } else {
                dp[i] = min(dp[i-1]+costs[0], dp[max(0, i-7)]+costs[1],
                        dp[max(0, i-30)]+costs[2]);
            }
        }

        //return dp[days.size()-1];
        return dp[365];
    }
private:
    int min(int x, int y) {
        return x < y ? x : y;
    }
    
    int min(int x, int y, int z) {
        return min(min(x, y), z);
    }
};

int main(int argc, char* argv[]) {
    //vector<int> days = {1,4,6,7,8,20};
    vector<int> days = {1,2,3,4,5,6,7,8,9,10,30,31};
    vector<int> costs = {2,7,15};
    Solution solution;
    int out = solution.getValue(days, costs);
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
