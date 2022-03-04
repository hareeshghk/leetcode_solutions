class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> mapper(26, -1);
        int s_len = s.length();
        for (int i = 0; i < s_len; ++i) {
            if (mapper[s[i]-'a'] == -1)
                mapper[s[i]-'a'] = i;
        }
        
        int left = s_len-1;
        int right = s_len-1;
        vector<int> result;
        for (int i = s_len-1; i >=0; --i) {
            left = min(left, mapper[s[i]-'a']);
            if (left == i) {
                result.push_back(right-left+1);
                right = left - 1;
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};