class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        sort(cards.begin(), cards.end());
        do {
            auto vals = backtrack(cards, 0, 3);
            for (auto val : vals) {
                if (isAns(val)) return true;
            }
        } while (next_permutation(cards.begin(), cards.end()));
        return false;
    }
    
    bool isAns(double val) {
        if (abs(val-24.0) < 0.0001) return true;
        return false;
    }
    
    bool nextPerm(vector<int> &cards) {
        int i = 3;
        for (i = 3; i >0; i--) {
            if(cards[i] > cards[i-1]) break;
        }
        
        if (i==0) return false;
        
        int j = i-1;
        
        int k;
        for (k = i; k < 4; ++k) {
            if (cards[k] < cards[j]) break;
        }
        swap(cards[j], cards[k-1]);
        
        sort(cards.begin()+j+1, cards.end());
        return true;
    }
    
    vector<double> backtrack(vector<int> &cards, int left, int right) {
        if (left == right) return {static_cast<double>(cards[left])};
        vector<double> result;
        for (int i = left; i < right; ++i) {
            auto vals1 = backtrack(cards, left, i);
            auto vals2 = backtrack(cards, i+1, right);
            
            for (int i = 0; i < vals1.size(); ++i) {
                for (int j = 0; j < vals2.size(); ++j) {
                    result.push_back(vals1[i]*vals2[j]);
                    result.push_back(vals1[i]/vals2[j]);
                    result.push_back(vals1[i]+vals2[j]);
                    result.push_back(vals1[i]-vals2[j]);
                }
            }
        }
        return result;
    }
};