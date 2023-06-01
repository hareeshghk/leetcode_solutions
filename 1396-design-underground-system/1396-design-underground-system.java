class StringInteger {
    public String s;
    public Integer i;
    public StringInteger(String str, Integer in) {
        s = str;
        i = in;
    }
}

class IntegerInteger {
    public Integer a;
    public Integer b;
    public IntegerInteger(Integer s1, Integer s2) {
        a = s1;
        b = s2;
    }
}

class UndergroundSystem {
    Map<Integer, StringInteger> checkInMap;
    Map<String, Map<String, IntegerInteger>> timeTakenMap;
    public UndergroundSystem() {
        checkInMap = new HashMap<>();
        timeTakenMap = new HashMap<>();
    }
    
    public void checkIn(int id, String stationName, int t) {
        checkInMap.put(id, new StringInteger(stationName, t));
    }
    
    public void checkOut(int id, String stationName, int t) {
        StringInteger checkinVal = checkInMap.get(id);
        if (timeTakenMap.get(checkinVal.s) == null) {
            timeTakenMap.put(checkinVal.s, new HashMap<>());
        }
        
        if (timeTakenMap.get(checkinVal.s).get(stationName) == null) {
            timeTakenMap.get(checkinVal.s).put(stationName, new IntegerInteger(0, 0));
        }
        
        IntegerInteger vals = timeTakenMap.get(checkinVal.s).get(stationName);
        vals.a += t - checkinVal.i;
        vals.b += 1;
    }
    
    public double getAverageTime(String startStation, String endStation) {
        return (timeTakenMap.get(startStation).get(endStation).a*1.0) / timeTakenMap.get(startStation).get(endStation).b;
    }
}

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem obj = new UndergroundSystem();
 * obj.checkIn(id,stationName,t);
 * obj.checkOut(id,stationName,t);
 * double param_3 = obj.getAverageTime(startStation,endStation);
 */