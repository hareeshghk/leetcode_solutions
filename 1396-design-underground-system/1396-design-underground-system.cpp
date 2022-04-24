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
        
        if (timeTaken.find(src.first + ","+stationName) == timeTaken.end()) {
            timeTaken[src.first + ","+stationName] = make_pair(0,0);
        }
        timeTaken[src.first + ","+stationName].first += t-src.second;
        timeTaken[src.first + ","+stationName].second++;
        
        // if (timeTaken.find(stationName + ","+src.first) == timeTaken.end()) {
        //     timeTaken[stationName + ","+src.first] = make_pair(0,0);
        // }
        // timeTaken[stationName + ","+src.first].first += t-src.second;
        // timeTaken[stationName + ","+src.first].second++;
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