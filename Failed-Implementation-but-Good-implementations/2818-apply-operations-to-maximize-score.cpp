class Node {
    public:
        int start, end, value, score;
        Node(int start, int end, int value, int score) {
            this->start = start;this->end = end; this->value = value; this->score=score;
        } 
    };
    
    class Solution {
    public:
        int maximumScore(vector<int>& nums, int k) {
            int n = nums.size();
            // visited sub array
            auto used = vector<vector<bool>>(n, vector<bool>(n, false));
            auto nodeMaxValueComp = [](Node &a, Node &b) {
                return a.value < b.value;
            };
    
            // calculate prime score.
            unordered_map<int, int> primescores = calculatePrimeScore(nums);
            // priority queue nodes as maxheap with maxvalue operator.
            auto pq = priority_queue<Node, vector<Node>, decltype(nodeMaxValueComp)>(nodeMaxValueComp);
            for (int i = 0; i < n; ++i) {
                pq.push(Node(i, i, nums[i], primescores[nums[i]]));
                used[i][i] = true;
            }
            
            long long int score = 1;
            int mod = 1000000007;
            // extract top k from priority queue.
            while (!pq.empty() && k--) {
                auto topNode = pq.top();
                pq.pop();
    
                score = (score * topNode.value)%mod;
                if (topNode.start - 1 >= 0 && used[topNode.start-1][topNode.end] == false) {
                    int ps = primescores[nums[topNode.start-1]];
                    if (ps >= topNode.score) {
                        pq.push(Node(topNode.start-1, topNode.end, nums[topNode.start-1], ps));
                    } else {
                        pq.push(Node(topNode.start-1, topNode.end, topNode.value, topNode.score));
                    }
                    used[topNode.start - 1][topNode.end] = true;
                }
    
                if (topNode.end + 1 < n && used[topNode.start][topNode.end+1] == false) {
                    int ps = primescores[nums[topNode.end+1]];
                    if (ps > topNode.score) {
                        pq.push(Node(topNode.start, topNode.end+1, nums[topNode.end+1], ps));
                    } else {
                        pq.push(Node(topNode.start, topNode.end+1, topNode.value, topNode.score));
                    }
                    used[topNode.start][topNode.end + 1] = true;
                }
            }
            return (int)score;
        }
    private:
        unordered_map<int, int> calculatePrimeScore(vector<int> &nums) {
            unordered_map<int, int> primescores;
            // do seive to get primes till 100000
            vector<bool> primes = vector<bool>(100001, true);
            primes[0] = false; primes[1] = false;
            for (int i = 2; i <= 50000; ++i) {
                if (primes[i] == false) continue;
                for (int j = i*2; j <= 100000; j+=i) {
                    primes[j] = false;
                }
            }
            unordered_set<int> primesSet;
    
            for (int i = 2; i < primes.size(); ++i) {
                if (primes[i] == true) {
                    primesSet.insert(i);
                }
            }
            for (auto num : nums) {
                if (primescores.find(num) != primescores.end()) continue;
    
                int score = 0;
                for (auto i : primesSet) {
                    if (num < i) continue;
                    if (num % i == 0) score++;
                }
                primescores[num] = score;
            }
            return primescores;
        }
    };