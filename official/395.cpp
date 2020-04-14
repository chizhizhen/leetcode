#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    //czz: overtime
    int longestSubstring(string s, int k) {
        int n = s.size();
        int l = 0;
        int r = n;
        int maxlen = 0;
        string res;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int len = j - i + 1;
                string buf = s.substr(i, len);
                if (isTrue(buf, k)) {
                    if (len > maxlen) {
                        maxlen = len;
                        res = buf;
                    }
                }
                else continue;
            }
        }
        cout << res << endl;
        return res.size();
    }
    bool isTrue(string str, int k) {
        unordered_map<char, int> dict;
        for (auto s:str) {
            if (dict.find(s) == dict.end()) dict[s] = 1;
            else dict[s] += 1;
        }
        unordered_map<char, int>::iterator iter;
        for (iter = dict.begin(); iter != dict.end(); iter++) {
            if (iter->second < k) return false;
        }
        return true;
    }

    //leetcode
    int longestSubstring2(string s, int k) {
        unordered_map<char, int> dict;
        for (auto c:s) {
            if (dict.find(c) == dict.end()) dict[c] = 1;
            else dict[c] += 1;
        }
        unordered_map<char, int>::iterator iter;
        bool flag1 = true;
        bool flag2 = true;
        for (iter = dict.begin(); iter != dict.end(); iter++) {
            //每个元素个数都大于等于k，返回s.size()
            if (iter->second < k) {
                flag1 = false;
            }
            //每个元素个数都小于k，返回0
            if (iter->second >= k) {
                flag2 = false;
            }
        }
        if (flag1) return s.size();
        if (flag2) return 0;
        
        vector<string> res;
        int i = 0;
        while(i < s.size()) {
            while(i < s.size() && dict[s[i]] < k) i++;
            int j = i + 1;
            for (;j < s.size(); j++) {
                if (dict[s[j]] < k) {
                    string temp = s.substr(i, j - i);;
                    res.push_back(temp);
                    break;//最短字符串
                }
            }
            if (j == s.size()) res.push_back(s.substr(i));
            i = j + 1;
        }

        int maxlen = 0;
        for (auto r:res) {
            maxlen = max(maxlen, longestSubstring2(r, k));;
        }
        return maxlen;
    }
};

int main(int argc, char* argv[]) {
    string s = argv[1];
    int k = atoi(argv[2]);
    
    Solution solution;
    //int out = solution.longestSubstring(s, k);
    int out = solution.longestSubstring2(s, k);
    
    cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
