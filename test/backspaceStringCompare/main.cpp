#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    bool getFlag(string A, string B) {
        string A_out;
        string B_out;
        int A_num = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] == '#') A_num += 1;
            else A_out += A[i];
        }
        int B_num = 0;
        for (int j = 0; j < B.size(); j++) {
            if (B[j] == '#') B_num += 1;
            else B_out += B[j];
        }
        return getChar(A_out, A_num) == getChar(B_out, B_num);
    }
private:
    char getChar(string A, int N) {
        if (A.size() <= N) return '\0';
        else return A[N];
    }
};

int main(int argc, char* argv[]) {
    //string A = "a##cd#";
    //string B = "#a#c";
    string A = "ab##";
    string B = "c#d#";
    Solution solution;
    bool out = solution.getFlag(A, B);
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
