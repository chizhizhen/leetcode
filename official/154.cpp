#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    //153.cpp
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int l = 0;
        int r = n - 1;
        while(l < r) {
            int m = (l + r) / 2;
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return nums[l];
    }
    //154.cpp
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (nums[m] > nums[r]) {
                l = m;
            } else if (nums[m] < nums[r]) {
                r = m;
            } else {
                r--;
            }
        }
        return nums[l];
    }
};
