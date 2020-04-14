#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int out = 0;
        for (int i = 0; i < s.size()-1; i++) {
            if (_dict[s[i+1]] > _dict[s[i]]) {
                out -= _dict[s[i]];
            } else if (_dict[s[i+1]] <= _dict[s[i]] ) {
                out += _dict[s[i]];
            }
        }
        return out + _dict[s[s.size()-1]];
    };

private:
    map<char, int> _dict = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    //map<int, string> _dict = {{1,"I"},{5,"V"},{10,"X"},{50,"L"},{100,"C"},{500,"D"},{1000,"M"}};
    vector<int> _list = {1,5,10,50,100,500,1000};
};

int main(int argc, char* argv[]) {
    //string A = "LVIII";
    string A = "MCMXCIV";
    Solution solution;
    int out = solution.romanToInt(A);
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
