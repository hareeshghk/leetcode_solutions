class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();

        vector<int> answer = vector<int>();

        answer.push_back(nums[0]);
        
        int second = 1;
        // O(N * C)
        while (second < n) {
            int gcd = GCD(answer.back(), nums[second]);

            if (gcd == 1) {
                answer.push_back(nums[second]);
            } else {
                int lcm = LCM(answer.back(), nums[second], gcd);
                answer.pop_back();

                while (!answer.empty()) {
                    int gcd = GCD(answer.back(), lcm);

                    if (gcd == 1) break;
                    lcm = LCM(answer.back(), lcm, gcd);
                    answer.pop_back();
                }
                answer.push_back(lcm);
            }
            second++;
        }
        return answer;
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