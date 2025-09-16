// 2, 3, 6
// 2, 6 -> // 6 

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();

        vector<int> st = vector<int>();

        st.push_back(nums[0]);
        
        int second = 1;
        while (second < n) {
            int gcd = GCD(st.back(), nums[second]);

            if (gcd == 1) {
                st.push_back(nums[second]);
            } else {
                int lcm = LCM(st.back(), nums[second], gcd);
                st.pop_back();

                while (!st.empty()) {
                    int gcd = GCD(st.back(), lcm);

                    if (gcd == 1) break;
                    lcm = LCM(st.back(), lcm, gcd);
                    st.pop_back();
                }
                st.push_back(lcm);
            }
            second++;
        }
        return st;
    }
private:
    inline int LCM(int a, int b, int gcd) {
        return ((a/gcd) * (b/gcd)) * gcd;
    }

    int GCD(int a, int b) {
        if (a == 0) {
            return b;
        }

        return GCD(b%a, a);
    }
};