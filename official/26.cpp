#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int num = 0;
        for (auto i:nums) {
            if (_dict.find(i) == _dict.end()) {
                _dict[i] = 1;
                num += 1;
            } else {
                continue;
            }
        }
        unordered_map<int, int>::iterator iter;
        for (iter = _dict.begin(); iter != _dict.end();iter++) {
            cout << iter->first << ", " << iter->second << endl;
        }
        return num;
    }
    
    // THIS IS BETTER 双指针法
    int removeDuplicates2(vector<int>& nums) {
        int slowp = 0;
        int size = nums.size();
        for (int fastp = 1; fastp < size; fastp++) {
            if (nums[fastp] != nums[slowp]) {
                nums[++slowp] = nums[fastp];
            }
        }
        for (auto a:nums) {
            cout << a << endl;
        }
        return slowp+1;
    }

private:
    unordered_map<int, int> _dict;
};

int main(int argc, char* argv[]) {
    vector<int> s = {0,0,1,1,1,2,2,3,3,4};
    
    Solution solution;
    int out = solution.removeDuplicates2(s);
    
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
