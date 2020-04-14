#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int out = nums[0]+nums[1]+nums[2];
        vector<int> res;
        int n = 3;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k) {
                int tmp = nums[i] + nums[j] + nums[k];
                out = (_abs(tmp,target) < _abs(out,target))?tmp:out;
                if (tmp == target) return target;
                else if (tmp - target > 0) {
                    k--;
                } else if(tmp - target < 0) {
                    j++;
                }
            }
        }
        return out;
    }
private:
    int _abs(int x, int y) {
        return abs(x - y);
    }
};

int main(int argc, char* argv[]) {
    vector<int> A = {-1, 2, 1, -4};
    int B = 1;
    Solution solution;
    int out = solution.threeSumClosest(A, B);
    cout << "out: " << out << endl;
    cout << "out: " << abs(-1) << endl;
    cout << "Congratulations!" << endl;
}
