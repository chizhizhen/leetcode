#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int area = 0;
        while (i < j) {
            area = max(area, min(height[i], height[j]) * (j - i));
            if (height[i] < height[j]) i++;
            //else if (height[i] > height[j]) j--;
            else j--;
        }
        return area;
    }
};

int main(int argc, char* argv[]) {
    vector<int> A = {1,8,6,2,5,4,8,3,7};
    int B = 49;
    Solution solution;
    int out = solution.maxArea(A);
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
