class Solution {
public:
    vector<vector<string>> result;
    string startWord;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        startWord = beginWord;
        vector<vector<int>> graph(n, vector<int>());
        int endWordIdx = -1;
        // create graph from wordlist O(N^2)
        for (int i = 0; i < n; i++) {
            if (wordList[i] == endWord) {
                endWordIdx = i;
            }
            for (int j =i+1; j < n; ++j) {
                if (isMatched(wordList[i], wordList[j])) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        
        if (endWordIdx == -1) return result;
        
        // for all words have a map of prev words,depth, this is to calclulate path
        vector<int> distances(n, INT_MAX);
        vector<vector<int>> parents(n, vector<int>());
        
        // create a queue with all words which are at one ditance from begin word.
        queue<int> q;
        
        for (int i = 0; i < n; i++) {
            if (isMatched(beginWord, wordList[i])) {
                q.push(i);
                distances[i] = 1;
                parents[i].push_back(-1);
            }
        }
        
        if (distances[endWordIdx] != INT_MAX) {
            FillResultPaths(parents, endWordIdx, wordList, {wordList[endWordIdx]});
            return result;
        }
        
        // do a bfs level wise, if at a level endword is reached stop bfs and dont add nodes to queue if its prev word not empty and cur depth is more than prev depth.
        int level = 2;
        bool endFound = false;
        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                auto cur = q.front();
                q.pop();
                
                for (auto child : graph[cur]) {
                    if (level > distances[child]) continue;
                    if (level != distances[child]) q.push(child);
                    distances[child] = level;
                    parents[child].push_back(cur);
                    if (child == endWordIdx) endFound = true;
                }
            }
            if (endFound) break;
            ++level;
        }
        
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < parents[i].size(); ++j) {
        //         cout << parents[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        if (distances[endWordIdx] != INT_MAX) {
            FillResultPaths(parents, endWordIdx, wordList, {wordList[endWordIdx]});
            return result;
        }
        
        return result;
    }
    
    void FillResultPaths(vector<vector<int>> &parents, int idx, vector<string>& wordList, vector<string> curpath) {
        if (parents[idx][0] == -1) {
            curpath.push_back(startWord);
            reverse(curpath.begin(), curpath.end());
            result.push_back(curpath);
            return;
        }
        
        for (int i = 0; i < parents[idx].size(); ++i) {
            curpath.push_back(wordList[parents[idx][i]]);
            FillResultPaths(parents, parents[idx][i], wordList, curpath);
            curpath.pop_back();
        }
    }
    
    bool isMatched(string &a, string &b) {
        int n = a.length();
        int diffcount = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) ++diffcount;
        }
        return (diffcount == 1);
    }
};