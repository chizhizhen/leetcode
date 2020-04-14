#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> out(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    out[i] = max(out[i], out[j]+1);
                }
            }
        }
        for (auto o:out) {
            cout << o << endl;
        }
        auto maxPosition = max_element(out.begin(), out.end()); //get max_ iterator
        int index = maxPosition - out.begin(); //print max index
        return *maxPosition;
    }

    int lengthOfLIS_BIN(vector<int>& nums) {
        vector<int> out;
        out.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            int id = out.size()-1;
            if (nums[i] > out[id]) out.push_back(nums[i]);
            else {
                int l = 0;
                int r = id;
                while (l < r) {
                    int m = (l + r) / 2;
                    if (nums[i] < out[m]) r = m - 1;
                    else if (nums[i] > out[m]) l = m + 1;
                }
                //替换比id小的里最大的多数
                out[l] = nums[i];
            }
        }
        for (auto o:out) {
            cout << o << endl;
        }
        return out.size();
    }
};

int main(int argc, char* argv[]) {
    vector<int> A = {10,9,2,5,3,7,101,18};
    
    Solution solution;
    //int out = solution.lengthOfLIS(A);
    int out = solution.lengthOfLIS_BIN(A);
    
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
