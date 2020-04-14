#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int l;
        int r;
        int out = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (prices[j] - prices[i] > out) {
                    out = prices[j] - prices[i];
                    r = j;
                    l = i;
                }
            }
        }
        return out;
    }
};

int main(int argc, char* argv[]) {
    vector<int> A = {7,1,5,3,6,4};
    
    Solution solution;
    vector<int> out = solution.removeDuplicates(A);
    
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
