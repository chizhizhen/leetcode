#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix[0].size();
        int l = matrix[0][0];
        int r = matrix[n-1][n-1];
        while (l < r) {
            int mid = (l+r)/2;

        }
        return l;
    }
    
    int getNum(vector<vector<int>> matrix, int t) {
        int count = 0;
        int n = matrix.size();
        int x = 0;
        while (x < n) {
            if (matrix[x][n-1] <= t) {
                count += n;
                cout << "===" << x << "==="<< count << endl;
                x++;
            } else {
                cout << "---" << x << "---"<< count << endl;
                bool flag = true;
                for (int j = n-1; j >= 0; j--) {
                    if (matrix[x][j] <= t) {
                        cout << "---" << x << "---"<< j << endl;
                        count += j+1;
                        x++;
                        flag = false;
                        break;
                    }
                }
                if (flag) break;
            }
        }
        return count;
    }

    int count(vector<vector<int>> matrix, int target) {
        int x = 0, y = matrix[0].size() -1;
        int num = 0;
        while(x < matrix.size() && y >= 0) {
            if(matrix[x][y] <= target) {
                num += y + 1;
                x++;
            }else {
                y--;
            }
        }
        return num;
    }
};

int main(int argc, char* argv[]) {
    //vector<vector<int>> A = {{1,5,9},{10,11,13},{12,13,15}};
    vector<vector<int>> A = {{1,5,9,10},{10,11,13,15},{12,13,15,17},{14,15,16,18}};
    int B = atoi(argv[1]);

    Solution solution;
    int out = solution.count(A, B);
    cout << "out: " << out << endl;
    out = solution.getNum(A, B);
    cout << "out: " << out << endl;
    
    cout << "Congratulations!" << endl;
}
