#include <vector>
using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        for (int i = 1; i < n-k; ++i) {
            ans.push_back(i);
        }
        
        for (int i = 0; i< k+1; i++) {
            ans.push_back(i&1?n-(i/2):n-k+i/2);
        }
        return ans;
    }
};
