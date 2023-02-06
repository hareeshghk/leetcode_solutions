class Solution {
    public List<List<Integer>> findSubsequences(int[] nums) {
        Set<List<Integer>> currentList = new HashSet<>();

        int n = nums.length;

        for (int i = 0; i < n; ++i) {
            Set<List<Integer>> nextList = new HashSet<>();
            for (List<Integer> l : currentList) {
                if (l.get(l.size()-1) <= nums[i]) {
                    List<Integer> temp = new ArrayList<Integer>(l);
                    temp.add(nums[i]);
                    nextList.add(temp);
                }
            }
            List<Integer> temp = new ArrayList<>();
            temp.add(nums[i]);
            currentList.add(temp);

            for (List<Integer> itr : nextList) {
                currentList.add(itr);
            }
        }

        List<List<Integer>> answer = new ArrayList<>();
        for (List<Integer> itr : currentList) {
            if (itr.size() != 1) {
                answer.add(itr);
            }
        }

        return answer;
    }
}