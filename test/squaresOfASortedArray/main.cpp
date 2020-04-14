#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    vector<int> getSquare(vector<int> A) {
        vector<int> out;
        map<int, int> dict;
        map<int, int>::iterator iter;
        int key;
        for (int i = 0; i < A.size(); i++) {
            dict[pow(A[i])] = i;
        }
        iter = dict.begin();
        while(iter != dict.end()) {
            out.push_back(iter->first);
            iter++;
        }
        return out;
    }
private:
    int pow(int x) {
        return x * x;
    }
};

int main(int argc, char* argv[]) {
    vector<int> A = {-4,-1,0,3,10};
    vector<int> B = {0,1,9,16,100};
    Solution solution;
    vector<int> out = solution.getSquare(A);
    for (auto i:out) {
        cout << "out: " << i << endl;
    }
    cout << "Congratulations!" << endl;
}
