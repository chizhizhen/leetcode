#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        for (int i = 0; i < strs.size(); i++) {
            string key = _getOrder(strs[i]);
            if (_strs_map.find(key) == _strs_map.end()) {
                _strs_map[key] = vector<string>(0, "");
                _strs_map[key].push_back(strs[i]);
            } else {
                _strs_map[key].push_back(strs[i]);
            }
        }
        unordered_map<string, vector<string>>::iterator iter;
        for (iter = _strs_map.begin(); iter != _strs_map.end(); iter++) {
            vector<string> tmps = iter->second;
            res.push_back(tmps);
        }
        return res;
    }
private:
    unordered_map<string, vector<string>> _strs_map;
    string _getOrder(string str) {
        string out;
        map<int, vector<char>> tmp;
        for (int i = 0; i < str.size();i++) {
            int v = str[i] - 'a';
            if (tmp.find(v) == tmp.end()) {
                tmp[v] = vector<char>(1, '\0');
                tmp[v].push_back(str[i]);
            } else {
                tmp[v].push_back(str[i]);
            }
        }
        map<int, vector<char>>::iterator iter;
        for (iter = tmp.begin(); iter != tmp.end(); iter++) {
            vector<char> cs = iter->second;
            for (auto c:cs) {
                out += c;
            }
        }
        return out;
    }
};

int main(int argc, char* argv[]) {
    vector<string> A = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution solution;
    vector<vector<string>> out = solution.groupAnagrams(A);
    for (auto i:out) {
        for (auto j:i) {
            cout << "out: " << j << endl;
        }
    }
    cout << "Congratulations!" << endl;
}
