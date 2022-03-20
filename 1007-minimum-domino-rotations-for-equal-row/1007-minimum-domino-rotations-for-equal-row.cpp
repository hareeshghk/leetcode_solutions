class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> commonnums{tops[0],bottoms[0]};
        
        for (int i = 1; i < tops.size(); i++) {
            for (int j = 0; j < commonnums.size(); ++j) {
                if (commonnums[j] != tops[i] && commonnums[j] != bottoms[i]) {
                    commonnums.erase(commonnums.begin()+j);
                    j--;
                }
            }
            
            if (commonnums.size() == 0) return -1;
        }
        
        int result = INT_MAX;
        
        for (int i = 0; i < commonnums.size(); ++i) {
            pair<int,int> changes = make_pair(0,0);
            for (int j = 0; j < tops.size(); ++j) {
                if (tops[j] != commonnums[i]) {
                    changes.first++;
                }
                if(bottoms[j] != commonnums[i]) {
                    changes.second++;
                }
            }
            
            result = min(result, min(changes.first, changes.second));
        }
        return result;
    }
};