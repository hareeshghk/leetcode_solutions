class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        Set<Integer> hs1, hs2;
        hs1 = new HashSet<>();
        hs2 = new HashSet<>();
        
        for (int num : nums1) {
            hs1.add(num);
        }
        
        for (int num : nums2) {
            hs2.add(num);
        }
        
        List<List<Integer>> answer = new ArrayList<>();
        
        answer.add(new ArrayList<>());
        answer.add(new ArrayList<>());
        
        for (int value : hs1) {
            if (!hs2.contains(value)) {
                answer.get(0).add(value);
            }
        }
        
        for (int value : hs2) {
            if (!hs1.contains(value)) {
                answer.get(1).add(value);
            }
        }
        
        return answer;
    }
}