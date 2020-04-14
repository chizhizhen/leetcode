#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getValue(int X, int Y) {
        int out = 0;
        while (X < Y) {
            out += 1;
            Y = Y/2;
            cout << Y << endl;
        }
        cout << X << Y << endl;
        out += X - Y;
        return out;
    }
};

// (3,10) = (3,5)+1 = (3,6)+2 = (3,3)+3
// (5, 8) = (5,4)+1 = 2
// (2, 3) = (2,4)+1 = (2,2)+2

class Solution2 {
public:
    int getValue(int X, int Y) {
        if (X >= Y) return X - Y;
        if (Y%2 == 0) return getValue(X, Y/2)+1;
        return getValue(X, Y+1) +1;
    }
};

int main(int argc, char* argv[]) {
    int X = 3;
    int Y = 10;
    //Solution solution;
    Solution2 solution;
    int out = solution.getValue(X, Y);
    cout << "output: " << out << endl;
    cout << "Congratulations!" << endl;
}
