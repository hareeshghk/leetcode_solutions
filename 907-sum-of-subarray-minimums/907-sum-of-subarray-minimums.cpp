#include <stack>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    const int mod = 1000000007;
    int sumSubarrayMins(vector<int>& arr) {
        stack<pair<int,int>> st;
        int n = arr.size();
        int result = 0;
        for (int i = 0; i < n; ++i) {
            int count = 0;
            while (!st.empty() && arr[st.top().first] > arr[i]) {
                st.pop();
            }
            
            if (st.empty()) {
                count = arr[i]*(i+1);
            } else {
                count = (arr[i]*(i-st.top().first)+st.top().second)%mod;
            }
            st.push(make_pair(i, count));
            result = (result + count)%mod;
        }
        return result;
    }
};
