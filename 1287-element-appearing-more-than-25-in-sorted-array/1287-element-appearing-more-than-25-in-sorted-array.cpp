class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        
        int minFreqForAnswer = n/4;
        
        for (int i = 0; i < n; ++i) {
            int j = i;
            while(j < n && arr[j] == arr[i]) {
                j++;
            }
            
            if (j-i > minFreqForAnswer) {
                return arr[i];
            }
        }
        
        return arr[0];
    }
};