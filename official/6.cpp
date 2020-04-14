#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int length = s.size();
        int mod = length/numRows;
        int div = length%numRows;
        int numCols = mod*2+div;
        vector<vector<char>> out(numRows, vector<char>(numCols, '\0'));
        int flag = 0;
        for (int i = 0;i < numCols;i++) {
            if (i%2 == 0) {
                for (int j = 0; j < numRows; j++) {
                    out[j][i] = s[flag++];
                }
            }
            else {
                out[1][i] = s[flag++];
            }
        }
        string res;
        for (auto i:out) {
            for (auto j:i) {
                res += j;
            }
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    //string A = "LEETCODEISHIRING";
    cout << "test: " << 17/3 << endl;
    string A = "PAYPALISHIRING";
    int B = 3;
    /*
     * L   C   I   R
     * E T O E S I I G
     * E   D   H   N
     * */
    Solution solution;
    string out = solution.convert(A, B);
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
