#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    bool out;
    bool canJump(vector<int>& nums) {
        int max = 0;//上一时刻能跳到的最远距离
        for (int i = 0; i < nums.size();i++) {
            if (max < i) return false;
            if (i+nums[i] > max) max = i+nums[i];
        }
        return true;
    }
};

/*
class Solution:
    def canJump(self, nums) :
        max_i = 0       #初始化当前能到达最远的位置
        for i, jump in enumerate(nums):   #i为当前位置，jump是当前位置的跳数
            if max_i>=i and i+jump>max_i:  #如果当前位置能到达，并且当前位置+跳数>最远位置  
                max_i = i+jump  #更新最远能到达位置
        return max_i>=i
*/

int main(int argc, char* argv[]) {
    vector<int> A = {2,3,1,1,4};
    
    Solution solution;
    bool out = solution.canJump(A);
    
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
