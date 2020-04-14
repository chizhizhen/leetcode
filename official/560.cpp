#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return 0;
        int out = 0;
        int sum = 0;
        unordered_map<int, int> dict;
        dict[0] = 1;
        for (auto num:nums) {
            sum += num;
            if (dict.find(sum-k) != dict.end()) out += dict[sum-k];
            dict[sum]++;
        }
        return out;
    }
};

int main(int argc, char* argv[]) {
    vector<int> A = {1,1,1};
    int B = 2;

    Solution solution;
    int out = solution.subarraySum(A, B);
    
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
