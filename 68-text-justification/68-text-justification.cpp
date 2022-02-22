class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int currentw = 0;
        int start = 0;
        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {
            // cout << currentw + words[i].length() + 1 << endl;
            if (currentw + words[i].length() + 1 <= maxWidth) {
                currentw += words[i].length() + 1;
            } else if (currentw + words[i].length() == maxWidth) {
                string cur = "";
                for (int k = start; k < i;k++) {
                    cur += words[k]+" ";
                }
                cur += words[i];
                ans.push_back(cur);
                start = i + 1;
                currentw = 0;
            } else {
                int num_words = i-start;
                if (num_words == 1) {
                    string cur = "";
                    cur += words[start];
                    for (int k = 0; k< maxWidth - words[start].length(); k++) {
                        cur += " ";
                    }
                    ans.push_back(cur);
                } else {
                    currentw -= num_words;
                    int remaining = maxWidth - currentw;
                    int assignall = (maxWidth - currentw)/(num_words-1);
                    int modval = (maxWidth - currentw)%(num_words-1);
                    string cur = "";
                    for (int k = start; k < i-1; k++) {
                        cur += words[k];
                        for (int l = 0; l < assignall; ++l) {
                            cur += " ";
                        }
                        if (modval > 0) cur += " ";
                        modval--;
                    }
                    cur += words[i-1];
                    ans.push_back(cur);
                }
                start = i;
                currentw = 0;
                i--;
            }
        }
        
        if (start == words.size()) return ans;
        
        string cur;
        for (int k = start; k < words.size(); k++) {
            cur += words[k] + " ";
        }
        
        int remaining = maxWidth - currentw;
        for (int k =0; k< remaining; ++k) {
            cur += " ";
        }
        ans.push_back(cur);
        return ans;
    }
};