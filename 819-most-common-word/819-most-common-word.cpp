class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban;
        
        for (auto str : banned) {
            ban.insert(str);
        }
        
        int freq = 0;
        string ans = "";
        
        unordered_map<string,int> counter;
        int start, end;
        for (start = getstart(paragraph, 0); start != paragraph.length();) {
            end = getend(paragraph, start);
            string curstr = paragraph.substr(start, end-start);
            // cout << curstr << endl;
            transform(curstr.begin(), curstr.end(), curstr.begin(), ::tolower);
            if (ban.count(curstr) == 0) {
            counter[curstr]++;
            if (counter[curstr] > freq) {
                freq = counter[curstr];
                ans = curstr;
            }
            }
            start = getstart(paragraph, end);
        }
        return ans;
    }
    
    int getstart(string &p, int idx) {
        int n = p.length();
        
        while (idx < n) {
            if (isalpha(p[idx])) return idx;
            ++idx;
        }
        return idx;
    }
    
    int getend(string &p, int idx) {
        int n = p.length();
        
        while (idx < n) {
            if (!isalpha(p[idx])) return idx;
            ++idx;
        }
        return idx;
    }
};