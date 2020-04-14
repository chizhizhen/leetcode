#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(1);
        result[0] = 0;
        for(int i = 1; i <= n; i++){
            int e = 1 << (i - 1);  
            cout << i << "," << e << endl;
            for(int j = result.size() - 1; j >= 0; j--){ 
                cout << j << "," << e << "," << result[j] << endl;
                result.push_back(e + result[j]);
            }
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    int A = atoi(argv[1]);
    
    Solution solution;
    vector<int> out = solution.grayCode(A);

    cout << "out: " << endl;
    for (auto o:out) {
        cout << "out: " << o << endl;
    }
    cout << "Congratulations!" << endl;
}
