#include <stdlib.h>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
    }
};

int main(int argc, char* argv[]) {
    int A = atoi(argv[1]);
    
    Solution solution;
    vector<int> out = solution.countBits(A);
    
    for (auto o:out) {
        cout << "out: " << o << endl;
    }
    cout << "Congratulations!" << endl;
}
