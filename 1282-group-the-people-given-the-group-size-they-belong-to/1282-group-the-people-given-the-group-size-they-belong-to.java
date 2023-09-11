class Solution {
    public List<List<Integer>> groupThePeople(int[] groupSizes) {
        Map<Integer, List<Integer>> sizeToIdxMap = new HashMap<>();
        
        for (int i = 0; i < groupSizes.length; ++i) {
            if (sizeToIdxMap.get(groupSizes[i]) == null) {
                sizeToIdxMap.put(groupSizes[i], new ArrayList<>());
            }
            
            sizeToIdxMap.get(groupSizes[i]).add(i);
        }
        
        List<List<Integer>> answer = new ArrayList<>();
        
        for(Map.Entry<Integer, List<Integer>> element : sizeToIdxMap.entrySet()) {
            int size = element.getKey();
            List<Integer> indices = element.getValue();
            int idx = 0;
            while (idx < indices.size()) {
                List<Integer> currentList = new ArrayList<>();
                for (int i = 0; i < size; ++i) {
                    currentList.add(indices.get(idx+i));
                }
                answer.add(currentList);
                idx += size;
            }
        }
        
        return answer;
    }
}