impl Solution {
    pub fn maximum_value_sum(nums: Vec<i32>, k: i32, edges: Vec<Vec<i32>>) -> i64 {
        let n = nums.len();

        let mut number_of_changes = 0;
        let mut minimum_change = -1;

        let mut answer: i64 = 0;
        let mut change = 0;
        let mut extras = 0;
        
        for i in 0..n {
            if nums[i] < (nums[i] ^ k) {
                answer += (nums[i] ^ k) as i64;
                number_of_changes += 1;

                change = (nums[i]^k) - nums[i];

                if minimum_change == -1 || change < minimum_change {
                    minimum_change = change;
                }
            } else {
                answer += nums[i] as i64;
                change = nums[i] - (nums[i]^k);

                if minimum_change == -1 || change < minimum_change {
                    minimum_change = change;
                }
            }

            if nums[i] == (nums[i] ^ k) {
                extras += 1;
            }
        }

        if number_of_changes % 2 == 0 || extras > 0 {
            return answer;
        }

        return answer - (minimum_change as i64);
    }
}