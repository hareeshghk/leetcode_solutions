class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> c1 = vector<int>(26, 0);

        for (int i = 0; i < s.length(); ++i) {
            c1[s[i]-'a']++;
        }

        int mod = 1000000007;
        
        for (int i = 1; i <= t; ++i) {
            vector<int> c2 = vector<int>(26, 0);

            for (int j = 0; j < 26; ++j) {
                c2[j] = c1[(26 + j-1)%26];
                if (j == 1) {
                    c2[j] = (c2[j] + c1[25]) % mod;
                }
            }

            c1 = c2;
        }

        int answer = 0;
        for (int i = 0; i < 26; ++i) {
            answer = (answer + c1[i]) % mod;
        }
        return answer;
    }
};

// class Solution {
//     int mod = 1000000007;
//     unordered_map<int, int> amap, bmap;
// public:
//     int lengthAfterTransformations(string s, int t) {
//         // we want length of z after each t transformations.
//         int answer = 0;

//         for(int i = 0; i < s.length(); ++i) {
//             answer = (answer + getLength(s[i], t)) % mod;
//         }

//         return answer;
//     }
// private:
//     int getLength(char c, int t) {
//         if (c == 'a') {
//             if (amap.find(t) != amap.end()) return amap[t];
//         } else if (c == 'b') {
//             if (bmap.find(t) != bmap.end()) return bmap[t];
//         }

//         int stepsToDouble = 26 - (c-'a');

//         if (t < stepsToDouble) {
//             return 1;
//         }

//         int value =  (getLength('a', t-stepsToDouble) + getLength('b', t-stepsToDouble)) % mod;

//         if (c=='a') {
//             amap[t] = value;
//         } else if (c == 'b') {
//             bmap[t] = value;
//         }
//         return value;
//     }
// };