class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int maxVal = -1;
        
        for (int candy : candies) {
           if (candy > maxVal) {
               maxVal = candy;
           } 
        }
        
        List<Boolean> answer = new ArrayList<>();
        
        for (int candy : candies) {
           if (candy + extraCandies >= maxVal) {
                answer.add(true);
            } else {
                answer.add(false);
            }
        }
        return answer;
    }
}