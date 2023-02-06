class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        int n = nums.length;
        int answer = 0;

        int runninPrefixMod = 0;
        int[] modCounts = new int[k];

        modCounts[0] = 1;

        for (int i = 0; i < n; ++i) {
            runninPrefixMod = (runninPrefixMod + (nums[i]%k)+k)%k;
            answer += modCounts[runninPrefixMod];
            modCounts[runninPrefixMod]++;
        }
        return answer;
    }
}