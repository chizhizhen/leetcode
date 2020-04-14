/***************************************************************************************************** 
 *
 * Let's define a function f(s) over a non-empty string s, which calculates the frequency of the 
 * smallest character in s. For example, if s = "dcce" then f(s) = 2 because the smallest character is 
 * "c" and its frequency is 2.
 * 
 * Now, given string arrays queries and words, return an integer array answer, where each answer[i] is 
 * the number of words such that f(queries[i]) < f(W), where W is a word in words.
 * 
 * Example 1:
 * 
 * Input: queries = ["cbd"], words = ["zaaaz"]
 * Output: [1]
 * Explanation: On the first query we have f("cbd") = 1, f("zaaaz") = 3 so f("cbd") < f("zaaaz").
 * 
 * Example 2:
 * 
 * Input: queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
 * Output: [1,2]
 * Explanation: On the first query only f("bbb") < f("aaaa"). On the second query both f("aaa") and 
 * f("aaaa") are both > f("cc").
 * 
 * Constraints:
 * 
 * 	1 <= queries.length <= 2000
 * 	1 <= words.length <= 2000
 * 	1 <= queries[i].length, words[i].length <= 10
 * 	queries[i][j], words[i][j] are English lowercase letters.
 ******************************************************************************************************/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution{
    public:
        vector<int> numSmallerByFrequency(vector<string> queries, vector<string> words) {
            vector<int> result;
            vector<int> words_freq;
            for (int i = 0; i < words.size(); i++) {
                // cout << get_freq(words[i]) << endl;
                words_freq.push_back(get_freq(words[i]));
            }
            sort(words_freq.begin(), words_freq.end());

            for (auto query :queries) {
                result.push_back(binary_search(get_freq(query), words_freq));
            }
            
            return result;
        }

        int get_freq(string& buffer) {
            int cnt = 0;
            char max_c = 'z' + 1;
            for (auto b : buffer) {
                if (b < max_c) {
                    cnt = 1;
                    max_c = b;
                } else if (b == max_c) {
                    cnt++;
                }
            }
            return cnt;
        }

        int binary_search(int key, vector<int>& freqs) {
            cout << "key" << key << endl;
            for (auto w : freqs) {
                cout << "w: " << w << endl;
            }
            int result;
            int low = 0;
            int top = freqs.size() - 1;
            int mid;
            while(low < top) {
                mid = low + (top - low) / 2;
                cout << "low: " << low << endl;
                cout << "mid: " << mid << endl;
                cout << "top: " << top << endl;
                
                if (freqs[mid] > key) {
                    top = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            
            cout << "low: " << low << endl;
            cout << "top: " << top << endl;

            low = freqs[low] > key ? low: low+1;
            result = freqs.size() - low;

            cout << "result: " << result << endl;
            return result;
        }
};

int main(int argc, char* argv[]) {
    vector<string> queries = {"bbb", "cc",};
    //vector<string> queries = {"cc",};
    vector<string> words = {"a", "aa", "aaa", "aaaa", "bbb",};
    //vector<string> words = {"a", "aa", "aaa", "aaaa",};
    vector<int> result;
    Solution solution;
    result = solution.numSmallerByFrequency(queries, words);
    //for (int i = 0; i < result.size(); i++) {
    //    cout << result[i] << endl;
    //}
   
    return 0;
}
