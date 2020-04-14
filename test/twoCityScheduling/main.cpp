/*
 * There are 2N people a company is planning to interview. The cost of flying the i-th person to city 
 * A is costs[i][0], and the cost of flying the i-th person to city B is costs[i][1].
 * 
 * Return the minimum cost to fly every person to a city such that exactly N people arrive in each 
 * city.
 * 
 * Example 1:
 * 
 * Input: [[10,20],[30,200],[400,50],[30,20]]
 * Output: 110
 * Explanation: 
 * The first person goes to city A for a cost of 10.
 * The second person goes to city A for a cost of 30.
 * The third person goes to city B for a cost of 50.
 * The fourth person goes to city B for a cost of 20.
 * 
 * The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
 * 
 * Note:
 * 
 * 	1 <= costs.length <= 100
 * 	It is guaranteed that costs.length is even.
 * 	1 <= costs[i][0], costs[i][1] <= 1000
 ******************************************************************************************************/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
    public:
        int minCost(vector<vector<int>> &input) {
            int cost = 0;
            map<int, vector<int>> key_val;
            map<int, vector<int>>::iterator iter;
            int numPerson = input.size()/2;
            
            for (int i = 0; i < input.size(); i++) {
                int dis = input[i][0] - input[i][1];
                if (key_val.find(dis) == key_val.end()) {
                    key_val[dis] = input[i];
                }
            }

            int index = 0;
            for (iter=key_val.begin(); iter != key_val.end(); iter++) {
                int key = iter->first;
                cout << "key: " << key << endl;
                vector<int> val = iter->second;
                cout << "A: " << val[0] << " , " << "B: " << val[1] << endl;
                if (index < numPerson) {
                    cost += val[0];
                } else if (index >= numPerson) {
                    cost += val[1];
                }
                index += 1;
            }
            
            return cost;
        }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> input = {{10,20}, {30,200}, {400,50}, {30,20}};
    int res = solution.minCost(input);
    cout << "final result: " << res << endl;
    cout << "Congratulations!" << endl;
    return 1;
}
