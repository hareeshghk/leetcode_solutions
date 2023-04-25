class SmallestInfiniteSet {
    int start;
    SortedSet<Integer> numbersSet;
    public SmallestInfiniteSet() {
        start = 1;
        numbersSet = new TreeSet<>();
    }
    
    public int popSmallest() {
        if (numbersSet.isEmpty()) {
            return start++;
        } else {
            int num = numbersSet.first();
            numbersSet.remove(num);
            return num;
        }
    }
    
    public void addBack(int num) {
        if (num >= start) {
            return;
        }
        
        numbersSet.add(num);
    }
}

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet obj = new SmallestInfiniteSet();
 * int param_1 = obj.popSmallest();
 * obj.addBack(num);
 */