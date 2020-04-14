#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    void set(string key, string value, int T) {
        hash_time.push_back(T);
        hash_value.push_back(value);
    }

    string get(string key, int T) {
        //if (hash_value.find(key)==hash_value.end()) return NULL;
        vector<int>::iterator it;
        if (T < *hash_time[key].begin()) {
            return NULL;
        }
        if (T > *hash_time[key].rbegin()) {
            return *hash_value[key].rbegin();
        }
        it = upper_bound(hash_time.begin(), hash_time.end(), T);
        return hash_value[key][it - hash_value.begin() - 1];
    }

private:
unordered_map<string, vector<int>> hash_time;
unordered_map<string, vector<string>> hash_value;
};

int main(int argc, char* argv[]) {
    vector<int> t;
    t.push_back(1);
    t.push_back(2);
    t.push_back(2);
    t.push_back(3);
    t.push_back(4);
    t.push_back(5);
    t.push_back(6);
    t.push_back(7);
    t.push_back(8);
    
    int low=lower_bound(t.begin(),t.end(),5)-t.begin();
    int upp=upper_bound(t.begin(),t.end(),5)-t.begin();
    cout<<low<<endl;
    cout<<upp<<endl;

    //Solution solution;
    //string out = solution.strWithout3a3b(A, B);
    //cout << "out: " << out << endl;
    cout << "Congratulations!" << endl;
}
