class Solution {
public:
    int endWordIdx;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        
        vector<vector<int>> graph(n, vector<int>{});
        
        endWordIdx = -1;
        
        for (int i = 0; i< n; i++) {
            if (wordList[i] == endWord) endWordIdx = i;
            for (int j = i+1; j < n; j++) {
                if (matched(wordList[i], wordList[j])) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        
        // end word not found
        if (endWordIdx == -1) return 0;
        
        
        // bfs
        queue<int> q;
        // n-1 is start word
        vector<bool> visited(n, false);
        int curlevel = 2;
        
        for (int i = 0; i < n; ++i) {
            if (matched(wordList[i], beginWord)) {
                q.push(i);
                visited[i] = true;
            }
        }
        
        while (!q.empty()) {
            int curlen = q.size();
            for (int i = 0; i < curlen; ++i) {
                auto cur = q.front();
                q.pop();
                if (cur == endWordIdx) return curlevel;
                
                for (auto nei : graph[cur]) {
                    if (!visited[nei]) {
                        q.push(nei);
                        visited[nei] = true;
                    }
                }
            }
            ++curlevel;
        }
        
        return 0;
    }
    
    bool matched(const string &a, const string &b) {
        int unmatched = 0;
        for (int i = 0; i< a.length(); i++) {
            if (a[i] != b[i]) unmatched++;
        }
        if (unmatched == 1) return true;
        return false;
    }
};