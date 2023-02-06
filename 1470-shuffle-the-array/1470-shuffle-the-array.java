class Solution {
    public int[] shuffle(int[] nums, int n) {
        int mod = 1024;
        for (int i = 0; i < 2*n; ++i) {
            if (i%2 == 0) {
                nums[i] = nums[i]|((nums[i/2]%mod)<<10); 
            } else {
                nums[i] = nums[i]|((nums[n+(i/2)]%mod)<<10);
            }
        }

        for (int i = 0; i <2*n; ++i) {
            nums[i] = nums[i]>>10;
        }
        return nums;
    }
}

// // With Extra Memory
// class Solution {
//     public int[] shuffle(int[] nums, int n) {
//         int[] answer = new int[2*n];

//         for (int i = 0; i < 2*n; ++i) {
//             if (i%2 == 0) {
//                 answer[i] = nums[i/2]; 
//             } else {
//                 answer[i] = nums[n+(i/2)];
//             }
//         }
//         return answer;
//     }
// }