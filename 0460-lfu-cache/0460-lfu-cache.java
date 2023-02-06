class Node {
    public int data;
    public int key;
    public int current_frequency;
    public Node(int k, int v) {
        data = v;
        key = k;
        current_frequency = 1;
    }
}

class LFUCache {
    private TreeMap<Integer, LinkedList<Node>> freq_store;
    private HashMap<Integer, Node> obj_store;
    private int _capacity;
    private int _curSize;

    public LFUCache(int capacity) {
        freq_store = new TreeMap<>();
        obj_store = new HashMap<>();
        _capacity = capacity;
        _curSize = 0;
    }
    
    public int get(int key) {
        if (!obj_store.containsKey(key)) return -1;

        Node n = obj_store.get(key);

        Integer cur_freq = n.current_frequency;
        freq_store.get(cur_freq).remove(n);
        if (freq_store.get(cur_freq).size() == 0) {
            freq_store.remove(cur_freq);
        }

        n.current_frequency++;
        if (!freq_store.containsKey(cur_freq+1)) {
            freq_store.put(cur_freq+1, new LinkedList<>());
        }

        freq_store.get(cur_freq+1).add(n);
        return n.data;
    }
    
    public void put(int key, int value) {
        if (_capacity == 0) return;
        if (!obj_store.containsKey(key)) {
            if (_curSize == _capacity) {
                Integer minFrequency = freq_store.firstKey();
                Node n = freq_store.get(minFrequency).poll();
                if (freq_store.get(minFrequency).size() == 0) {
                    freq_store.remove(minFrequency);
                }
                
                Integer storedKey = n.key;
                obj_store.remove(storedKey);

                --_curSize;
            }

            Node in = new Node(key, value);
            obj_store.put(key, in);
            if (!freq_store.containsKey(1)) {
                freq_store.put(1, new LinkedList<>());
            }
            freq_store.get(1).add(in);
            ++_curSize;
        } else {
            Node n = obj_store.get(key);
            Integer cur_freq = n.current_frequency;

            freq_store.get(cur_freq).remove(n);
            if (freq_store.get(cur_freq).size() == 0) {
                freq_store.remove(cur_freq);
            }

            n.current_frequency++;
            n.data = value;

            if (!freq_store.containsKey(cur_freq+1)) {
                freq_store.put(cur_freq+1, new LinkedList<>());
            }

            freq_store.get(cur_freq+1).add(n);
        }
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */