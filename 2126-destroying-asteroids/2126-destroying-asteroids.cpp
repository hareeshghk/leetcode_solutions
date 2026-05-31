class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        long long bigmass = mass;
        for (int i = 0; i < asteroids.size(); ++i) {
            if (bigmass < asteroids[i]) return false;
            bigmass += asteroids[i];
        }
        return true;
    }
};