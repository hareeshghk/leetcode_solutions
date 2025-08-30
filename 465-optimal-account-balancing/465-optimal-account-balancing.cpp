#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> flows;
        for (auto trans : transactions) {
            flows[trans[0]]+= trans[2];
            flows[trans[1]]+= -trans[2];
        }
        
        vector<int> values;
        for (auto flow: flows) {
            if (flow.second != 0) values.push_back(flow.second);
        }
        return recurse(values, 0);
    }
    
    int recurse(vector<int> &v, int idx) {
        if(idx == v.size()) return 0;
        while (idx < v.size() && v[idx] == 0) idx++;
        
        int res = INT_MAX;
        for (int i = idx+1; i < v.size(); ++i) {
            if (v[i] * v[idx] < 0) {
                v[i] += v[idx];
                res = min(res, 1 + recurse(v, idx+1));
                v[i] -= v[idx];
            }
        }
        return res==INT_MAX?0:res;
    }
};
