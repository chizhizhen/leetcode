#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    vector<int> quickSort(vector<int>& nums, int l, int r) {
        if (l < r) {
            int i = l;
            int j = r;
            int x = nums[l];
            while (i < j) {
                while(i < j && nums[j] > x) j--;
                if (i < j) nums[i++] = nums[j];
                while(i < j && nums[i] < x) i++;
                if (i < j) nums[j--] = nums[i];
            }
            nums[i] = x;
            quickSort(nums, l, i-1);
            quickSort(nums, i+1, r);
        }
        return nums;
    }
    
    vector<int> MergeSort(vector<int>& nums, int l, int r) {
        if (l < r) {
            int m = (l + r) / 2;
            MergeSort(nums, l, m-1);
            MergeSort(nums, m+1, r);
            Merge(nums, l, m, r);
        }
        return nums;
    }
    void Merge(vector<int>& nums, int l, int m, int r) {
        vector<int> temp;
        int i = l;
        int j = m + 1;
        while (i <= m && j <= r) {
            if (nums[i] < nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }
        while(i <= m) temp.push_back(nums[i++]);
        while(j <= r) temp.push_back(nums[j++]);
        for (int k = 0; k < temp.size(); k++) {
            nums[k] = temp[k];
        }
    }
};

int main(int argc, char* argv[]) {
    vector<int> A = {34,65,12,43,67,5,78,10,3,70};
    cout << "Before:" << endl;
    for (auto a:A) {
        cout << a << endl;
    }
    Solution solution;
    vector<int> out = solution.MergeSort(A, 0, A.size()-1);
    cout << "After:" << endl;
    for (auto a:out) {
        cout << a << endl;
    }
    cout << "Congratulations!" << endl;
}
