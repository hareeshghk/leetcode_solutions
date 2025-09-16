// 2, 3, 6
// 2, 6 -> // 6 

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();

        stack<int> st = stack<int>();

        st.push(nums[0]);
        
        int second = 1;
        while (second < n) {
            int gcd = GCD(st.top(), nums[second]);

            if (gcd == 1) {
                st.push(nums[second]);
            } else {
                int lcm = LCM(st.top(), nums[second]);
                st.pop();

                while (!st.empty()) {
                    int gcd = GCD(st.top(), lcm);

                    if (gcd == 1) break;
                    lcm = LCM(st.top(), lcm);
                    st.pop();
                }
                st.push(lcm);
            }
            second++;
        }

        vector<int> answer = vector<int>();
        while (!st.empty()) {
            answer.push_back(st.top());
            st.pop();
        }

        reverse(answer.begin(), answer.end());
        return answer;
    }
private:
    int LCM(int a, int b) {
        int gcd = GCD(a, b);

        return ((a/gcd) * (b/gcd)) * gcd;
    }

    int GCD(int a, int b) {
        if (a == 0) {
            return b;
        }

        return GCD(b%a, a);
    }
};