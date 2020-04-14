/*
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 */
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

map<int, string> kpt_map = {{0, "nose"}, {1, "left_eye"}, {2, "right_eye"}};

class Solution {
  public:
    vector<int> TwoSum(vector<int> input_array, int target) {
      vector<int> results;
      int len = input_array.size();
      for(int i = 0; i < len; i++) {
          for(int j = i+1; j < len; j++) {
              if (input_array[i]+input_array[j] == target) {
                  results.push_back(i);
                  results.push_back(j);
              }
          }
      }
      return results;
    }

    vector<int> twoSum(vector<int> nums, int target) {
        vector<int> result;
        unordered_map<int, int> m;
        for (int i=0; i<nums.size(); i++) {
            if ( m.find(target - nums[i]) == m.end() ) { // unfinded
                m[nums[i]] = i;
            }else{
                result.push_back(m[target - nums[i]]);
                result.push_back(i);
            }
        
            // unordered_map<int, int>::iterator iter;
            // iter = m.begin();
            // cout << "Judge.\t" << i << "\t" << nums[i] << endl;
            // while(iter != m.end()) {
            //     cout << iter->first << " : " << iter->second << endl;
            //     iter++;
            // }
        }
        
        return result;
    }
};

int main(int argc, char *argv[]) {
    vector<int> input = {2, 7, 11, 15, 2, 7};
    int target = 9;
    Solution solution;
    vector<int> res = solution.twoSum(input, target);
    // cout << "results num:\t" << res.size() << endl;
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    
    //map<int, string>::iterator iter = kpt_map.find(0);
    //if (iter != kpt_map.end()) {
    //    cout << "First " << iter->first << endl;
    //    cout << "Second " << iter->second << endl;
    //}
    
    return 0;
}
