#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    //暴力遍历
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int iii = 0;
        int jjj = 0;
        int kkk = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) iii++;
            else if (nums[i] == 1) jjj++;
            else if (nums[i] == 2) kkk++;
        }

        for (int i = 0; i < iii; i++) {
            nums[i] = 0;
        }
        for (int i = iii; i < iii+jjj; i++) {
            nums[i] = 1;
        }
        for (int i = iii+jjj; i < n; i++) {
            nums[i] = 2;
        }
    }

    // 双指针法
    void sortColors2(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        for (int i = 0; i <= r;){
            if (nums[i] == 0) {
                swap(nums, l, i);
                l++;
                i++;
            }
            else if (nums[i] == 2) {
                swap(nums, i, r);
                r--;
            }
            else {
                i++;
            }
        }
    }
private:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};

int main(int argc, char* argv[]) {
    vector<int> s = {2,0,2,1,1,0};
    
    Solution solution;
    solution.sortColors2(s);
    
    for (auto o:s) {
        cout << "out: " << o << endl;
    }
    cout << "Congratulations!" << endl;
}
