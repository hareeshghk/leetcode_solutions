impl Solution {
    pub fn is_zero_array(nums: Vec<i32>, queries: Vec<Vec<i32>>) -> bool {
        let n = nums.len();

        let mut pre_points = vec!(0; n+1);

        let s = queries.len();

        for query in queries {
            pre_points[query[0] as usize]-=1;
            pre_points[query[1] as usize +1]+=1;
        }

        let mut offset = 0;
        for i in 0..n {
            offset += pre_points[i];

            if nums[i] + offset > 0 {
                return false;
            }
        }
        return true;
    }
}