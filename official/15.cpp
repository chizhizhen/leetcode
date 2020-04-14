#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> out;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        if (nums[0] > 0 || nums[size-1] < 0) return {};
        for (int i = 0; i < size; i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue; //remind same -1 appears
            int j = i + 1;
            int k = size - 1;
            int T = 0 - nums[i]; 
            while(j < k) {
                if (nums[j] + nums[k] == T) {
                    out.push_back({nums[i], nums[j], nums[k]});
                    while(j < k && nums[j] == nums[j+1]) j++;
                    while(j < k && nums[k] == nums[k-1]) k--;
                    j++;
                    k--;
                }
                else if (nums[j] + nums[k] < T) j++;
                else k--;
            }
        }
        return out;
    }
};

int main(int arch, char* argv[]) {
    vector<int> A = {-1, 0, 1, 2, -1, -4};
    int B = 0;
    Solution solution;
    vector<vector<int>> out = solution.threeSum(A);
    for (auto i:out) {
        cout << "res: " << endl;
        for (auto j:i) {
            cout << j << endl;
        }
    }
    return 1;
}
