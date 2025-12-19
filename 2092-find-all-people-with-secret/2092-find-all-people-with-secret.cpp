class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int, int>>> g = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());

        for (auto& meeting : meetings) {
            g[meeting[0]].push_back({meeting[1], meeting[2]});
            g[meeting[1]].push_back({meeting[0], meeting[2]});
        }

        g[0].push_back({firstPerson, 0});
        g[firstPerson].push_back({0, 0});

        auto comp = [](pair<int,int> a, pair<int, int> b) {
            if (a.first > b.first) return true;
            return false;
        };

        auto pq = priority_queue<pair<int, int>, vector<pair<int,int>>, decltype(comp)>(comp);
        unordered_set<int> visited;

        pq.push({-1, 0});

        vector<int> answer = vector<int>();

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int time = top.first;
            int node = top.second;
            if (visited.find(node) != visited.end()) continue;
            visited.insert(node);
            answer.push_back(node);

            for (auto neighbour : g[node]) {
                if (neighbour.second >= time && visited.find(neighbour.first) == visited.end()) {
                    pq.push({neighbour.second, neighbour.first});
                }
            }
        }
        return answer;
    }
};