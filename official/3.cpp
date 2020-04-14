#include <iostream>
#include <vector>
#include <set>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int getValue(string s) {
        //vector<char> numList={'1','2','2','3','3','3'};
        //set<char> numSet;
        //for(int i=0;i<6;i++)
        //{
        //    numSet.insert(numList[i]);
        //}
        //cout << printSet(numSet) << endl;
        //return 0;
        int res = 0;
        set<char> t;
        int left = 0;
        int right = 0;
        while (right < s.size()) {
            if (t.find(s[right]) == t.end()) {
                t.insert(s[right++]);
                cout << "l:"<<left<<", r:"<<right << "if: " << printSet(t) << endl;
                cout << t.size() << endl;
                res = max(res, (int)t.size());
            }  else {
                t.erase(s[left++]);
                cout << "l:"<<left<<", r:"<<right<< "else: " << printSet(t) << endl;
                cout << t.size() << endl;
            }
        }
        return res;
    }
    int lengthOfLongestSubstring(string s) {
        string out;
        string temp;
        int size = s.size();
        for (int i = 0; i < size; i++) {
            if (isInside(s[i], temp)) {
                temp = s[i]; 
            }
            else temp += s[i];
            out = maxString(out, temp);
        }
        return out.size();
    }
private:
    bool isInside(char a, string b) {
        for (auto i : b) {
            if (a == i) return true;
        }
        return false;
    }
    string maxString(string A, string B) {
        return A.size() > B.size() ? A:B;
    }
    string printSet(set<char> A) {
        string s;
        for(set<char>::iterator it=A.begin() ;it!=A.end();it++) {
            s += *it;
        }
        return s;
    }
};

int main(int argc, char* argv[]) {
    //string A = "pwwkew";
    string A = "dvdf";
    Solution solution;
    //int out = solution.lengthOfLongestSubstring(A);
    int out = solution.getValue(A);
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
