#include <cmath>
#include <deque>
#include <vector>

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        deque<int> st;
        
        bool currentbroken;
        for (int i = 0; i < n; ++i) {
            if (!st.empty() && asteroids[st.back()] > 0 && asteroids[i] < 0) {
                currentbroken = false;
                while (!st.empty() && asteroids[st.back()] > 0) {
                    if (asteroids[st.back()] < abs(asteroids[i])) {
                        st.pop_back();
                    } else if (asteroids[st.back()] == abs(asteroids[i])) {
                        st.pop_back();
                        currentbroken = true;
                        break;
                    } else {
                        currentbroken = true;
                        break;
                    }
                }
                if (!currentbroken) st.push_back(i);
            } else {
                st.push_back(i);
            }
        }
        
        vector<int> result;
        while (!st.empty()) {
            result.push_back(asteroids[st.front()]);
            st.pop_front();
        }
        return result;
    }
};
