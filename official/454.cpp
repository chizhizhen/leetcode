#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res = 0;
        unordered_map<int, int> dict;
        for (int a:A) {
            for (int b:B) {
                int key = a + b;
                if (dict.find(key) == dict.end()) {
                    dict[key] = 1;
                } else {
                    dict[key] += 1;
                }
            }
        }
        for (int c:C) {
            for (int d:D) {
                int key = 0 - (c + d);
                if (dict.find(key) != dict.end()) {
                    res += dict[key];
                }
            }
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    vector<int> A = {1, 2};
    vector<int> B = {-2, -1};
    vector<int> C = {-1, 2};
    vector<int> D = {0, 2};

    Solution solution;
    int out = solution.fourSumCount(A, B, C, D);
    
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
