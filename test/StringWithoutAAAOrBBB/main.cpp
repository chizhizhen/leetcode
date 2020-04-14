#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string ans="";
        char a='a',b='b';
        if(A<B){
            swap(A,B);
            swap(a,b);
        }
        while(A||B){
            cout << "A: " << A << endl;
            cout << "B: " << B << endl;
            cout << "out: " << ans << endl;
            if(A>0) {ans+= a; A--;}
            if(A>B) {ans+= a; A--;}
            if(B>0) {ans+= b; B--;}
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    int A = atoi(argv[1]);
    int B = atoi(argv[2]);
    Solution solution;
    string out = solution.strWithout3a3b(A, B);
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
