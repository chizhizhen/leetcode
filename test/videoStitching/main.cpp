#include <iostream>
#include <vector>

using namespace std;

#define DEBUG 1

//considered as 01-bags, 可将长度视为背包容量, 

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {

        //sort the clips
        //sort(clips.begin(), clips.end(), [](vector<int>& x, vector<int>& y) {
        //    return x[0] < y[0] || (x[0] == y[0] && x[1] < y[1]);
        //});
        sort(clips.begin(), clips.end());

        if (DEBUG) {
            print(clips);
        }
        //exit(1);

        vector<int> dp(T+1, -1);

        for (auto c : clips) {
            //edge case: out of the range
            if (c[0] > T) continue;

            // if clip is started from 0, then just simple initalize to 1
            if (c[0] == 0) {
                for (int i=c[0]; i<=min(T,c[1]); i++) dp[i] = 1;
                cout << "#####" << endl;
                print(c);
                print(dp);
                continue;
            }

            if (dp[c[0]] == -1 ) continue;

            int m = dp[c[0]];

            for (int i = c[0] + 1; i<= min(T, c[1]); i++) {
                if ( dp[i] > 0 ) m = min(m, dp[i]);
                else dp[i] = m + 1;
            }
            cout << "#####" << endl;
            print(c);
            print(dp);
        }

        ////print(dp);
        return dp[T];
    }

    //used for debug
    void print(vector<vector<int>>& clips) {
        for (auto c : clips) {
            cout << "[" << c[0] <<","<< c[1] << "]"<< " ";
        }
        cout << endl;
    }

    void print(vector<int>& v) {
        for (auto i : v) {
            cout << i << ", ";
        }
        cout << endl;
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    //vector<int> in = {0,4,1,3,2,6};
    //sort(in.begin(), in.end());
    //for (int i =0 ; i < in.size(); i++) {
    //    cout << in[i] << endl;
    //}
    
    vector<vector<int>> in = {{0,2},{4,6},{8,10},{1,9},{1,5},{5,9}};
    int T = 10;
    //vector<vector<int>> in = {{0,4},{2,8}};
    //int T = 5;
    //for (int i = 0; i < in.size(); i++) {
    //    for (int j = 0; j < in[0].size(); j++) {
    //        cout << in[i][j] << endl;
    //    }
    //}
    //cout << in.size() << endl;
    //cout << in[0].size() << endl;
    int res = solution.videoStitching(in, T);
    cout << "Congratulations!" << endl;
}
