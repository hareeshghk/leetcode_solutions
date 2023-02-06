class SummaryRanges {
    TreeMap<Integer, Integer> intervals;
    public SummaryRanges() {
        intervals = new TreeMap<>();
    }
    
    public void addNum(int value) {
        int left = value, right = value;
        Map.Entry<Integer, Integer> leftBound = intervals.floorEntry(value);

        if (leftBound != null) {
            int previousEnd = leftBound.getValue();

            if (previousEnd >= value) {
                return;
            }

            if (previousEnd == value-1) {
                left = leftBound.getKey();
            }
        }

        Map.Entry<Integer, Integer> rightBound = intervals.higherEntry(value);

        if (rightBound != null && rightBound.getKey() == value + 1) {
            right = rightBound.getValue();
            intervals.remove(rightBound.getKey());
        }

        intervals.put(left, right);
    }
    
    public int[][] getIntervals() {
        int[][] result = new int[intervals.size()][];
        int count = 0;
        for (Integer key : intervals.keySet()) {
            result[count] = new int[2];
            result[count][0] = key;
            result[count][1] = intervals.get(key);
            count++;
        }

        return result;
    }
}

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(value);
 * int[][] param_2 = obj.getIntervals();
 */