#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int num = 0;
        long long mul = 1;
        for (int i = 1; i <= n; i++) {
            mul *= i;
        }
        vector<int> res;
        while (mul / 10) {
            res.push_back(mul % 10);
            mul = mul / 10;
        }
        res.push_back(mul);
        for (int i = 0; i < res.size(); i++) {
            if (res[i] == 0) num++;
            else break;
        }
        return num;
    }
    
    //10 = 2*5
    //1*2*3*4*5*6*7...
    int trailingZeroes(int n) {
        int num = 0;
        while (n > 0) {
            num++;
            n /=5;
        }
        return num;
    }
};
