class Solution {
    public int minimumDeviation(int[] nums) {
        TreeSet<Integer> values = new TreeSet<>();
        
        for (int num : nums) {
            if (num %2 == 1) values.add(num*2);
            else values.add(num);
        }
        
        int answer = Integer.MAX_VALUE;
        
        while (true) {
            int curMax = values.last();
            int curMin = values.first();
            
            values.remove(curMax);
            
            answer = Math.min(answer, curMax - curMin);
            
            if (curMax %2 == 0) {
                curMax/=2;
                values.add(curMax);
            } else {
                break;
            }
        }
        return answer;
    }
}