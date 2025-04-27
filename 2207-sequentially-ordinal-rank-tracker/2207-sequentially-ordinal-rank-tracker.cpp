class PlaceWithScore {
    string name;
    int score;
public:
    PlaceWithScore(string n, int s) {
        name = n;
        score = s;
    }

    string getName() const {return name;}
    int getScore() const {return score;}
};

class SORTracker {
public:
    inline static auto minheapFunc = [](const PlaceWithScore &a, const PlaceWithScore &b) {
        if (a.getScore() > b.getScore()) {
            return true;
        } else if (a.getScore() < b.getScore()) {
            return false;
        } else {
            return a.getName() < b.getName();
        }
    };

    inline  static auto  maxheapFunc = [](const PlaceWithScore &a, const PlaceWithScore &b) {
        if (a.getScore() < b.getScore()) {
            return true;
        } else if (a.getScore() > b.getScore()) {
            return false;
        } else {
            return a.getName() > b.getName();
        }
    };

    inline static auto isBetter = [](const PlaceWithScore &a, const PlaceWithScore &b) {
        if (a.getScore() > b.getScore()) {
            return true;
        } else if (a.getScore() < b.getScore()) {
            return false;
        } else {
            return a.getName() < b.getName();
        }
    };

    SORTracker() : minheap(minheapFunc), maxheap(maxheapFunc) {
        bestLocationFindCount = 0;
    }
    
    void add(string name, int score) {
        auto pws = PlaceWithScore(name, score);
        if (minheap.empty()) {
            minheap.push(pws);
        } else if (isBetter(pws, minheap.top())) {
            minheap.push(pws);
        } else {
            maxheap.push(pws);
        }
    }
    
    string get() {
        bestLocationFindCount++;

        while (minheap.size() > bestLocationFindCount) {
            auto val = minheap.top();
            minheap.pop();
            maxheap.push(val);
        }

        while (minheap.size() < bestLocationFindCount) {
            auto val = maxheap.top();
            maxheap.pop();
            minheap.push(val);
        }
        return minheap.top().getName();
    }
private:
    int bestLocationFindCount;
    priority_queue<PlaceWithScore, vector<PlaceWithScore>, decltype(minheapFunc)> minheap;
    priority_queue<PlaceWithScore, vector<PlaceWithScore>, decltype(maxheapFunc)> maxheap;
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */