#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    vector<int> getSum(vector<int> A, int B) {
        vector<int> out;
        unordered_map<int, int> _dict;
        for (int i = 0;i < A.size(); i++) {
            if (_dict.end() == _dict.find(B-A[i])) {
                _dict[A[i]] = i;
            } else {
                out.push_back(_dict[B-A[i]]);
                out.push_back(i);
            }
        }
        return out;
    }
};

int main(int argc, char* argv[]) {
    vector<int> A = {2,11,7,15};
    int B = 9;
    Solution solution;
    vector<int> out = solution.getSum(A, B);
    for(auto i:out) {
        cout << "out: " << i << endl;
    }
    cout << "Congratulations!" << endl;
}
