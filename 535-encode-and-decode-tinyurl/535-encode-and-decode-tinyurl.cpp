class Solution {
    unordered_map<string,string> mapper;
    int counter;
public:
    Solution() {
        counter = 0;
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        auto key = createkey();
        mapper[key] = longUrl;
        return key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mapper[shortUrl];
    }
    
    string createkey() {
        ++counter;
        return to_string(counter);
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));