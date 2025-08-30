#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        // size for storing size seen till now.
        int currentsize = 0;
        
        // start index od word of each row in answer.
        int start = 0;
        
        for (int i = 0; i < words.size(); i++) {
            // filling row.
            if (currentsize + words[i].length() + 1 <= maxWidth) {
                currentsize += words[i].length() + 1;
            } else if (currentsize + words[i].length() == maxWidth) {
                // if row is perfect fit.
                string cur = "";
                for (int k = start; k < i;k++) {
                    cur += words[k]+" ";
                }
                cur += words[i];
                ans.push_back(cur);
                start = i + 1;
                currentsize = 0;
            } else {
                // if current word made size to cross the max width.
                int num_words = i-start;
                if (num_words == 1) {
                    string cur = "";
                    cur += words[start];
                    for (int k = 0; k< maxWidth - words[start].length(); k++) {
                        cur += " ";
                    }
                    ans.push_back(cur);
                } else {
                    currentsize -= num_words;
                    int remainingSpace = maxWidth - currentsize;
                    int extraspaces = remainingSpace/(num_words-1);
                    int modval = remainingSpace%(num_words-1);
                    string cur = "";
                    for (int k = start; k < i-1; k++) {
                        cur += words[k];
                        for (int l = 0; l < extraspaces; ++l) {
                            cur += " ";
                        }
                        if (modval > 0) cur += " ";
                        modval--;
                    }
                    cur += words[i-1];
                    ans.push_back(cur);
                }
                // since current got failed to get added, so next start is current word.
                start = i;
                currentsize = 0;
                // going one back so for loop increments and try again.
                i--;
            }
        }
        
        // if last row was a perfect match return ans.
        if (start == words.size()) return ans;
        
        // since it's last row filling with only one space after each word.
        string cur;
        for (int k = start; k < words.size(); k++) {
            cur += words[k] + " ";
        }
        
        int remaining = maxWidth - currentsize;
        for (int k =0; k< remaining; ++k) {
            cur += " ";
        }
        ans.push_back(cur);
        return ans;
    }
};
