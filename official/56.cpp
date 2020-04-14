#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        return res;
    }
};

int main(int argc, char* argv[]) {
    vector<vector<int>> A = {{1,3},{2,6},{8,10},{15,18}};

    Solution solution;
    vector<vector<int>> out = solution.merge(A);
    
    for (auto a:out) {
        cout << "#####" << endl;
        for (auto b:a) {
            cout << b << endl;
        }
    }
    cout << "Congratulations!" << endl;
}
