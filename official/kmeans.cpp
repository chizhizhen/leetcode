#include <iostream>
using namespace std;

class Solution {
public:
    struct cluster {
        float x;
        float y;
        vector<float> center;
        vector<int> nums;
    }
    float getDistance(vector<float>& x, vector<float>& y) {
        float sum = 0.0;
        for (int i = 0; i < x.size(); i++) {
            sum += pow(x[i]-y[i], 2);
        }
        return sqrt(sum);
    }
    float getD(vector<cluster> clusters) {
        float distance = 0.0;
        for (auto c:clusters) {
            ;
        }
        return distance;
    }
    vector<cluster> kMeans(vector<vector<float>> input, int k) {
        int m = input.size();
        int n = input[0].size();
        vector<cluster> clusters(k);
        for (int i = 0; i < k; i++) {
            int r = rand()%k;
            clusters[i].center.push_back(input[r]);
            //clusters[i].nums.push_back(r);
        }
        
        while (true) {
            /*for (auto &c:clusters) {
                int temp = 0;
                if (c.samples.size() != 0) temp++;
                if (temp == k) break;
            }*/
            float dist = getD(clusters);
            for (int i = 0; i < m; i++) {
                int id = 0;
                float distance = getDistance(input[id], clusters[id].center);
                for (int j = 1; j < k; j++) {
                    float dis = getDistance(input[i], clusters[j].center);
                    if (dis < distance) {
                        distance = dis;
                        id = j;
                    }
                }
                clusters[id].centers.erase(input[i]);
                clusters[id].centers.push_back(input[i]);
                clusters[id].samples.push_back(j);
            }
            float curdis = getD(clusters);
            if (curdis < dist) break;
            
            for (int i = 0; i < k; i++) {
            vector<float> val;
            for (int j = 0; j < clusters[i].samples.size(); j++) {
                int s = clusters[i].samples[j];
                for (int k = 0; k < n; k++) {
                    val[k] += input[s][id];
                    if (k == clusters[i].samples.size()-1) {
                        clusters[i].centers[k] = val[k]/clusters[i].samples.size();
                    }
                }
            }
            }
            
        }
        
        return clusters;
    }
}

int main() {
    cout << "Hello World!" << endl;
}
