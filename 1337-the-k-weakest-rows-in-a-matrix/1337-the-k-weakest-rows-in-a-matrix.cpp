class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<pair<int,int>> counter(m);
        for (int i = 0; i < m; ++i) {
            counter[i] = make_pair(0, i);
            for (int j=0; j < n; ++j) {
                if (mat[i][j] == 0) break;
                counter[i].first++;
            }
        }
        struct comp {
          bool operator()(pair<int,int> &a, pair<int,int> &b) {
              return a.first > b.first || (a.first==b.first && a.second>b.second);
          }  
        };
        make_heap(counter.begin(), counter.end(), comp());
        
        vector<int> result;
        for (int i = 0; i < k; i++) {
            pop_heap(counter.begin(), counter.end(), comp());
            result.push_back(counter[counter.size()-1].second);
            counter.pop_back();
        }
        return result;
    }
};