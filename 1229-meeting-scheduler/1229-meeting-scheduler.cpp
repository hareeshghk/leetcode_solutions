class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        
        int m = slots1.size();
        int n = slots2.size();
        
        int i=0,j=0;
        
        vector<int> result;
        
        while (i < m && j < n) {
            if (slots1[i][1] < slots2[j][0]) {
                i++;
            } else if (slots2[j][1] < slots1[i][0]) {
                j++;
            } else {
                if (GetDuration(slots1[i], slots2[j]) >= duration) {
                    int start = max(slots1[i][0], slots2[j][0]);
                    int end = duration+start;
                    return {start, end};
                }
                if (slots1[i][1] < slots2[j][1]) {
                    i++;
                } else {
                    j++;
                }
            }
        }
        return result;
    }
    
    int GetDuration(const vector<int> &a, const vector<int> &b) {
         return min(a[1], b[1]) - max(a[0], b[0]);
    }
};