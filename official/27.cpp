#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int begin = 0;//保证begin前面都是不等于val的值
        int end = nums.size() - 1;//end处的值等于val的时候end才会-1
        while (begin <= end) {
            if(nums[begin] == val && nums[end] == val) {
                end--;
            } else if (nums[begin] == val && nums[end] != val) {
                nums[begin] = nums[end];
                begin++;
                end--;
            } else if (nums[begin] != val && nums[end] == val) {
                begin++;
                end--;
            } else {
                begin++;
            }
        }
        return begin;
    }
    
    // THIS IS BETTER!!!
    int removeElement2(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();
        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1]; // reduce array size by one
                n--;
            } else {
                i++;
            }
        }
        return n;
    }
};

int main(int argc, char* argv[]) {
    vector<int> s = {0,0,1,1,1,2,2,3,3,4};
    int A = 2;
    Solution solution;
    int out = solution.removeElement2(s, A);
    cout << "out: " << out << endl;
    for (auto i:s) {
        cout << i << endl;
    }
    cout << "Congratulations!" << endl;
}
