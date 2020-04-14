#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        int n = needle.size();
        if (n == 1) {
            for (int i = 0; i < haystack.size(); i++) {
                if (haystack[i] == needle[0]) {
                    return i;
                }
            }
            return -1;
        }
        int flag = -1;
        for (int i = 0;i < haystack.size(); i++) {
            int m = 1;
            if (haystack[i] == needle[0]) {
                for (int j = 1; j < n; j++) {
                    if (haystack[i+j] == needle[j]) m += 1;
                }
            }
            if (m == n) {
                flag = i;
                break;
            }
        }
        return flag;
    }
};

int main(int argc, char* argv[]) {
    //string A = "hello";
    //string B = "lo";
    string A = "baabbbbababbbabab";
    string B = "abbab";
    Solution solution;
    int out = solution.strStr(A, B);
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
    return 1;
}
