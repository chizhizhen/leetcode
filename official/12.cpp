#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string out;
        for (int i = 0; i < _strs.size(); i++) {
            while (num >= _value[i]) {
                out += _strs[i];
                num -= _value[i];
            }
        }
        return out;
    }

private:
    //1000->100->10->1
    map<int, string> _dict = {{1,"I"},{5,"V"},{10,"X"},{50,"L"},{100,"C"},{500,"D"},{1000,"M"}};
    vector<string> _strs = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    vector<int> _value = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
};

int main(int argc, char* argv[]) {
    int A = atoi(argv[1]);
    Solution solution;
    string out = solution.intToRoman(A);
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
