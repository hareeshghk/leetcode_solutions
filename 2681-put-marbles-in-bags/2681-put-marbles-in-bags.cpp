#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        // you need k-1 cuts
        vector<long long> cutPairs;
        for (int i = 0; i < weights.size()-1; ++i) {
            cutPairs.push_back(((long long)weights[i])+weights[i+1]);
        }
        sort(cutPairs.begin(), cutPairs.end());
        long long answer = 0;
        // max pair sum, get top k-1
        // min pair sum, get min k-1
        int n = cutPairs.size();
        for (int i = 0; i < k-1; ++i) {
            answer += (cutPairs[n-1-i]-cutPairs[i]);
        }
        return answer;
    }
};
