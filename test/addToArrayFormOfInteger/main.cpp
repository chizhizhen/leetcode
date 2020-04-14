#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> getValue(vector<int> A, int K) {
        long out = 0;
        for (int i = A.size(), j = 0; j < A.size(); i--, j++) {
            out += A[j]*pow(10, i-1);
        }
        out += K;
        
        cout << "###" << out << endl;
        int num = getLength(out);
        cout << "###" << num << endl;
        
        vector<int> res(num, 0);
        int div;
        int mod;
        for (int i = num-1; i >=0; i--) {
            mod = out%10;
            out = out/10;
            res[i] = mod;
        }

        for (auto i:res) {
            cout << "res: " << i << endl;
        }

        return res;
    }

private:
    int getLength(int X) {
        int length = 0;
        while (X) {
            X = X/10;
            length += 1;
        }
        return length;
    }
};

int main(int argc, char* argv[]) {
    //vector<int> A = {1, 2, 0, 0};
    //int K = 34;
    //vector<int> A = {2,1,5};
    //int K = 806;
    vector<int> A = {9,9,9,9,9,9,9,9,9,9};
    int K = 1;
    Solution solution;
    vector<int> out = solution.getValue(A, K);
    cout << "Congratulations!" << endl;
}
