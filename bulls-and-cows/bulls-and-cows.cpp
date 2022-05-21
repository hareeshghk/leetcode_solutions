class Solution {
public:
    string getHint(string secret, string guess) {
        int bullcount=0, matchcount=0;
        
        // string result = "";
        
        unordered_map<char,int> counter;
        
        for (int i = 0; i < secret.length(); ++i) {
            if (guess[i] == secret[i]) bullcount++;
            counter[secret[i]]++;
        }
        
        for (int i = 0; i < guess.length(); ++i) {
            if (counter.find(guess[i]) == counter.end()) continue;
            
            counter[guess[i]]--;
            matchcount++;
            if (counter[guess[i]] == 0) counter.erase(guess[i]);
        }
        
        return to_string(bullcount)+"A"+to_string(matchcount-bullcount)+"B";
    }
};