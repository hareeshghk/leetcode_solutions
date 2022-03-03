class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<bool> destroyed(n, false);
        
        for (int i = 0; i < n; ++i) {
            if (asteroids[i] < 0) {
                int j = i-1;
                while (j >= 0) {
                    if (destroyed[j]) {
                        j--;
                        continue;
                    }
                    
                    if (asteroids[j] < 0) {
                        j--; continue;
                    }
                    if (asteroids[j] < abs(asteroids[i])) {
                        destroyed[j] = true;
                    } else if (asteroids[j] == abs(asteroids[i])) {
                        destroyed[j] = true;
                        destroyed[i] = true;
                        break;
                    } else {
                        break;
                    }
                    j--;
                }
                if (j >= 0) destroyed[i] = true;
            }
        }
        
        vector<int> result;
        
        for (int i = 0; i < n; i++) {
            if (!destroyed[i]) result.push_back(asteroids[i]);
        }
        return result;
    }
};