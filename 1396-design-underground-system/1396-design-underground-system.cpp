class UndergroundSystem {
    unordered_map<string, pair<int,int>> timeTaken;
    unordered_map<int, pair<string,int>> checkins;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkins[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        auto src = checkins[id];
        
        string key = src.first + ","+stationName;
        if (timeTaken.find(key) == timeTaken.end()) {
            timeTaken[key] = make_pair(0,0);
        }
        
        auto &val_pair = timeTaken[key];
        val_pair.first += t-src.second;
        val_pair.second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto val = timeTaken[startStation+","+endStation];
        
        return (val.first*1.0)/val.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */