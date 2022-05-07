class WordDistance {
    unordered_map<string, vector<int>> word_map;
public:
    WordDistance(vector<string>& wordsDict) {
        for (int i = 0; i < wordsDict.size(); ++i) {
            word_map[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        auto& first_ids = word_map[word1];
        auto& second_ids = word_map[word2];
        
        int mindistance = INT_MAX;
        
        int i = 0, j= 0;
        while (i < first_ids.size() && j < second_ids.size()) {
            mindistance = min(mindistance, abs(first_ids[i]-second_ids[j]));
            
            if (first_ids[i] < second_ids[j]) {
                ++i;
            } else {
                ++j;
            }
        }
        return mindistance;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */