#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getValue(vector<int> A, vector<vector<int>> queries) {
        vector<int> out;
        for(auto query:queries) {
            int i = query[0];
            int j = query[1];
            A[j] += i;
            out.push_back(getEven(A));    
        }
        return out;
    }
private:
    int getEven(vector<int> input) {
        int out = 0;
        for (auto i:input) {
            if (i%2 == 0) {
                out += i;
            }
        }
        return out;
    }
};

int main(int argc, char* argv[]) {
    vector<int> A = {1, 2, 3, 4};
    vector<vector<int>> queries = {{1,0}, {-3,1}, {-4,0}, {2,3}};
    vector<int> out;
    Solution solution;
    out = solution.getValue(A, queries);
    for (auto i:out) {
        cout << i << endl;
    }
    cout << "Congratulations!" << endl;
}
