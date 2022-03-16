class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int result = 0;
        
        for (int i = 0; i < n; ++i) {
            int j = i, k = i, count = 0;
            while (j-count >=0 && k+count < n) {
                if (s[k+count] == s[j-count]) count++;
                else break;
            }
            result += count;
            
            j = i;k=i+1;count = 0;
            while (j-count >=0 && k+count < n) {
                if (s[j-count] == s[k+count]) count++;
                else break;
            }
            result += count;
        }
        return result;
    }
};