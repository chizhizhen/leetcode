#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:

};

int main(int argc, char* argv[]) {
    vector<int> A = {1, 0, -1, 0, -2, 2};
    int B = 0;
    Solution solution;
    string out = solution.strWithout3a3b(A, B);
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
