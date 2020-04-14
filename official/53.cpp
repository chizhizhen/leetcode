#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int out = nums[0];
        int sum = out;
        int begin = 0;
        int end = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (sum + nums[i] > nums[i]) { 
                sum += nums[i];
            }
            else {
                sum = nums[i];
                begin = i;
            }
            if (sum > out) {
                out = sum;
                end = i;
            }
            //out = max(sum, out);
        }
        cout << begin << "," << end << endl;
        return out;
    }
private:
    int max(int x, int y) {
        return x>y?x:y;
    }
};

int main(int argc, char* argv[]) {
    vector<int> A = {-2,1,-3,4,-1,2,1,-5,4};
    
    Solution solution;
    int out = solution.maxSubArray(A);
    
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
