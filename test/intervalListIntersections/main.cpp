#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> getValue(vector<vector<int>> A, vector<vector<int>> B) {
        vector<vector<int>> res;
        int i = 0;
        int j = 0;
        int m = A.size();
        int n = B.size();
        while (i < m && j < n) {
            if (A[i][0] > B[j][1]) j++;
            else if (A[i][1] < B[j][0]) i++;
            else {
                cout << A[i][0] << ", " << A[i][1] << endl;
                cout << B[j][0] << ", " << B[j][1] << endl;
                res.push_back(getOverlap(A[i], B[j]));
                if (A[i][1] < B[j][1]) i++;
                else j++;
            }
        }

        return res;
    }

private:
    bool isOverlap(vector<int> A, vector<int> B) {
        if (A[0] > B[1] || A[1] < B[0]) {
            return 0;
        }
        else {
            return 1;
        }
    }

    vector<int> getOverlap(vector<int> A, vector<int> B) {
        vector<int> res(2, 0);
        if (isOverlap(A, B)) {
            res[0] = max(A[0], B[0]);
            res[1] = min(A[1], B[1]);
        }
        for (auto i:res) {
            cout << "overlap: " << i << endl;
        }
        return res;
    }
};


int main(int argc, char* argv[]) {
    vector<vector<int>> A = {{0,2},{5,10},{13,23},{24,25}};
    vector<vector<int>> B = {{1,5},{8,12},{15,24},{25,26}};
    Solution solution;
    vector<vector<int>> out = solution.getValue(A, B);
    for (int i = 0; i < out.size(); i++) {
        cout << "1st, 2nd: " << out[i][0] << ", " << out[i][1] << endl;
    }
    cout << "Congratulations!" << endl;
}
