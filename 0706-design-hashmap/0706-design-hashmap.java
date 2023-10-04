class MyHashMap {
    int[] innerMap;

    public MyHashMap() {
        innerMap = new int[1000001];
        Arrays.fill(innerMap, -1);
    }
    
    public void put(int key, int value) {
        innerMap[key] = value;
    }
    
    public int get(int key) {
        return innerMap[key];
    }
    
    public void remove(int key) {
        innerMap[key] = -1;
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */