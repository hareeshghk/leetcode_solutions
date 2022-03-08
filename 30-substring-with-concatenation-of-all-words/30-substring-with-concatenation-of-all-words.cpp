class Solution {
public:
    int k, checklen, wordsnum;
    unordered_map<string, int> wordset;
    vector<int> findSubstring(string s, vector<string>& words) {
        k = words[0].length();
        wordsnum = words.size();
        for (int i = 0; i < wordsnum; i++) {
            wordset[words[i]]++;
        }
        
        checklen = k*wordsnum;
        // cout << "totoal len: " << checklen << endl;

        
        vector<int> ans;
        for (int i = 0; i < s.length()-checklen+1; i++) {
            if (perfect(s, i)) ans.push_back(i);
        }
        return ans;
    }
    
    bool perfect(string &s, int pos) {
        unordered_map<string, int> visited;
        for (int i = 0; i < checklen; i+=k) {
            string s2 = s.substr(pos+i, k);
            // cout << s2 << endl;
            if (wordset.find(s2) == wordset.end()) return false;
            visited[s2]++;
            if (visited[s2] > wordset[s2]) return false;
        }
        return true;
    }
};