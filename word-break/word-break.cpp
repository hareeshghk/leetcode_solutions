class Solution {
public:
    int mod = 100000007;
    const int numchars = 27;
    unordered_set<string> wordset;
    vector<vector<int>> dp;
    vector<long long int> shash;
    long long int calculatehash(const string &s, int i, int j) {
        long long int ha = 0;
        for (int k =i; k <=j; k++) {
            ha = ((ha*numchars)%mod + (s[k]-'a')+1)%mod;
        }
        return ha;
    }
    
    void fillshash(string &s) {
        shash.resize(s.length());
        long long int ha = 0;
        for (int i = 0; i < s.length(); ++i) {
            ha = ((ha*numchars)%mod + (s[i]-'a') + 1)%mod;
            shash[i] = ha;
        }
        return;
    }
    
    long long int pow(int a, int b) {
        long long int base = a;
        long long int result = 1;
        while (b != 0) {
            if (b&1) result = (result*base)%mod;
            b = b>>1;
            base = (base*base)%mod;
        }
        return result;
    }
    
    long long int partshash(int i, int j) {
        long long int a = shash[j];
        long long int b = (i-1)>=0?shash[i-1]:0;
        
        return a - ((b*pow(numchars, j-i+1))%mod);
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.resize(s.length(), vector<int>(s.length(), -1));
        // fillshash(s);
        // inserting word dict words hashes into set.
        for (auto str : wordDict) {
            wordset.insert(str);
        }
        
        return solve(s, 0, s.length()-1);   
    }
    
    bool solve(const string &s, int i, int j) {
        if (dp[i][j] != -1) return dp[i][j]==0?false:true;
        
        if (wordset.find(s.substr(i, j-i+1)) != wordset.end()) {
            dp[i][j] = 1;
            return true;
        }
        
        for(int l = i; l < j; ++l) {
            if(solve(s, i, l) && solve(s, l+1, j)) {
                dp[i][j] = 1;
                return true;
            }
        }
        dp[i][j] = 0;
        return false;
    }
};