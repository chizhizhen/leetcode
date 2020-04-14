#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>m;
        for(auto num : nums)    //  存到哈希结构里
            m[num]++;
        vector<pair<int,int >>v;
        vector<int>ans;
        for(auto it : m)        //  存到用于对value排序的容器里
            v.push_back(make_pair(it.first,it.second));
        sort(v.begin(),v.end(),[](pair<int,int> &a,pair<int,int> &b)->bool{return a.second>b.second;}  );
        for(auto a:v) {
            cout << a.first << "," << a.second << endl;
        }
        for(int i=0;k;++i,--k)
            ans.push_back(v[i].first);
        return ans;
    }
};

int main(int argc, char* argv[]) {
    vector<int> A = {1,1,2,2,2,3};
    
    Solution solution;
    vector<int> out = solution.topKFrequent(A, 2);
    for(auto o:out) {
        cout << "out: " << o << endl;
    }
    cout << "Congratulations!" << endl;
}
