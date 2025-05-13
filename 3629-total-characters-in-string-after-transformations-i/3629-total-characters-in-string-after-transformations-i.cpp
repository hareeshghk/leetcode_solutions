class Solution {
    int mod = 1000000007;
    unordered_map<int, int> amap, bmap;
public:
    int lengthAfterTransformations(string s, int t) {
        // we want length of z after each t transformations.
        int answer = 0;

        for(int i = 0; i < s.length(); ++i) {
            answer = (answer + getLength(s[i], t)) % mod;
        }

        return answer;
    }
private:
    int getLength(char c, int t) {
        if (c == 'a') {
            if (amap.find(t) != amap.end()) return amap[t];
        } else if (c == 'b') {
            if (bmap.find(t) != bmap.end()) return bmap[t];
        }

        int stepsToDouble = 26 - (c-'a');

        if (t < stepsToDouble) {
            return 1;
        }

        int value =  (getLength('a', t-stepsToDouble) + getLength('b', t-stepsToDouble)) % mod;

        if (c=='a') {
            amap[t] = value;
        } else if (c == 'b') {
            bmap[t] = value;
        }
        return value;
    }
};