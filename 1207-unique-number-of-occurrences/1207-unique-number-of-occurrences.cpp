class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freq;
        for (auto num : arr) {
            freq[num]++;
        }
        
        unordered_set<int> freqs;
        for (auto val : freq) {
            if (freqs.count(val.second) != 0) return false;
            freqs.insert(val.second);
        }
        return true;
    }
};