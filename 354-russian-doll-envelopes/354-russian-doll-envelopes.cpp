class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b) {return a[0]<b[0]||(a[0]==b[0] && a[1]>b[1]);});
        int n = envelopes.size();
        vector<int> store;
        
        store.push_back(envelopes[0][1]);
        
        for (int i =1; i <n;i++) {
            if (envelopes[i][1] > store[store.size()-1]) {
                store.push_back(envelopes[i][1]);
            } else {
                int suited_idx = searchIndex(store, envelopes[i][1]);
                store[suited_idx] = envelopes[i][1];
            }
        }
        return store.size();
    }
    
    int searchIndex(vector<int> &store, int val) {
        int left = 0, right = store.size()-1;
        
        int ans = -1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            
            if (store[mid] == val) return mid;
            
            if (store[mid] < val) {
                left++;
            } else {
                ans = mid;
                right--;
            }
        }
        return ans;
    }
};