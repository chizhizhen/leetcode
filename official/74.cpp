#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0;
        int r = m * n - 1;
        // 二分查找(l<=r)
        while (l <= r) {
            int mid = (l + r) / 2;
            int row = mid / n;
            int col = mid % n;
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] > target) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
};

int main(int argc, char* argv[]) {
    vector<vector<int>> A = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    int B = 3;

    Solution solution;
    bool out = solution.searchMatrix(A, B);
    
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
