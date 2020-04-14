#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin()+n/2, nums.end());
        int mid = *(nums.begin()+n/2);
        cout << mid << endl;
    }
};

int main(int argc, char* argv[]) {
    //vector<int> A = {1,3,2,2,3,1};
    vector<int> A = {1,2,3,4};
    
    Solution solution;
    solution.wiggleSort(A);
    
    for(auto out:A) {
        cout << "out: " << out << endl;
    }
    cout << "Congratulations!" << endl;
}
