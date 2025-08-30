#include <algorithm>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();

        // find Max element
        int maxElement = 0;
        for (auto num : nums) {
            maxElement = max(maxElement, num);
        }
        // Get prime numbers in sorted order.
        vector<int> primes= getPrimes(maxElement);
        
        vector<int> primeScores = vector<int>(n, 0);
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            int score = 0;
            for (auto prime : primes) {
                if (prime * prime > num) break;
                if (num % prime != 0) continue;
                score++;
                while (num %prime == 0) num/=prime;
            }
            if (num > 1) score++;
            primeScores[i] = score;
        }

        // monotnic stack to get nearest bigger prime count both left and right side.
        stack<int> st;
        vector<int> nearBigToLeft(n, -1);
        vector<int> nearBigToRight(n, n);

        for (int i = 0; i < n; ++i) {
            int ps = primeScores[i];
            while (!st.empty() && primeScores[st.top()] < ps) {
                nearBigToRight[st.top()] = i;
                st.pop();
            }
            if (!st.empty()) {
                nearBigToLeft[i] = st.top();
            }
            st.push(i);
        }

        vector<pair<int, int>> sortedArray(n);
        for (int i = 0; i < n; ++i) {
            sortedArray[i] = pair<int, int>(nums[i], i);
        }
        sort(sortedArray.begin(), sortedArray.end(), greater<>());

        auto counter = vector<long long int>(n);
        for (int i = 0; i < n; ++i) {
            counter[i] = ((long long int)(nearBigToRight[i]-i)) * (i - nearBigToLeft[i]);
        }

        long long int score = 1;
        int mod = 1000000007;
        for (int i = 0; i < n && k > 0; ++i) {
            score = (score * GetPowerValue(sortedArray[i].first, min((long long)k, counter[sortedArray[i].second]), mod))%mod;
            k -= counter[sortedArray[i].second];
        }
        return (int)score;
    }
private:
    long long int GetPowerValue(long long int base, int power, int mod) {
        long long result = 1;
        while (power > 0) {
            if (power & 1) {
                result = (result * base) % mod;
            }
            base = (base * base) %mod;
            power /= 2;
        }
        return result;
    }

    vector<int> getPrimes(int limit) {
        // Seive to get primes till limit
        vector<bool> isPrime = vector<bool>(limit+1, true);
        isPrime[0] = false; isPrime[1] = false;
        
        vector<int> primes;

        for (int i = 2; i <= limit; ++i) {
            if (!isPrime[i]) continue;

            primes.push_back(i);
            
            for (long long j = (long long)i*i; j <= limit; j+=i) {
                isPrime[j] = false;
            }
        }
        
        return primes;
    }
};
