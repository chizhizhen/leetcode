#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int out = INT_MAX;
        int sum = 0;
        int left = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            while (sum >= s) {
                out = min(out, i - left + 1);
                sum -= nums[left++];
            }
        }
        return out == INT_MAX?0:out;
    }
};

int main(int argc, char* argv[]) {
    vector<int> A = {2,3,1,2,4,3};
    int B = 7;
    
    Solution solution;
    int out = solution.minSubArrayLen(B, A);
    
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}

