class Leaderboard {
    unordered_map<int, int> scoreBoard;
    map<int, int> scoreCount;
public:
    Leaderboard() {
    }
    
    void addScore(int playerId, int score) {
        if (scoreBoard.find(playerId) == scoreBoard.end()) {
            scoreBoard[playerId] = score;
            scoreCount[score]++;
        } else {
            int val = scoreBoard[playerId];
            scoreCount[val]--;
            if (scoreCount[val] == 0) scoreCount.erase(val);
            scoreBoard[playerId] += score;
            scoreCount[val+score]++;
        }
    }
    
    int top(int K) {
        int answer = 0;
        for (auto itr = scoreCount.rbegin(); itr != scoreCount.rend(); itr++) {
            answer += (min(K, itr->second) * itr->first);
            K-=itr->second;
            if (K <= 0) break;
        }
        return answer;
    }
    
    void reset(int playerId) {
        int val = scoreBoard[playerId];
        scoreCount[val]--;
        if (scoreCount[val] == 0) scoreCount.erase(val);
        scoreBoard.erase(playerId);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */