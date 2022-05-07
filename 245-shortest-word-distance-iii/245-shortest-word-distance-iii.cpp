class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        vector<int> w1, w2;
        
        for (int i = 0; i < wordsDict.size(); ++i) {
            if (wordsDict[i] == word1) {
                w1.push_back(i);
            } else if (wordsDict[i] == word2) {
                w2.push_back(i);
            }
        }
        
        if (word1 == word2) w2=w1;
        
        int mindistance = INT_MAX;
        int i = 0, j = 0;
        while (i < w1.size() && j < w2.size()) {
            if (w1[i] != w2[j]) mindistance = min(mindistance, abs(w1[i]-w2[j]));
            
            if (w1[i] < w2[j]) ++i;
            else ++j;
        }
        
        return mindistance;
    }
};