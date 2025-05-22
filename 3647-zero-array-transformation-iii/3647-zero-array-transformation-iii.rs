use std::collections::BinaryHeap;

impl Solution {
    pub fn max_removal(nums: Vec<i32>, mut queries: Vec<Vec<i32>>) -> i32 {
        queries.sort_by(|a, b| a[0].cmp(&b[0]));

        let mut max_heap = BinaryHeap::new();
        let mut operations = 0;
        let n = nums.len();
        let mut delta_array = vec![0; n+1];
        let mut j = 0;
        for i in 0..n {
            operations += delta_array[i];

            while j < queries.len() && queries[j][0] == i as i32 {
                max_heap.push(queries[j][1]);
                j += 1;
            }

            while operations < nums[i] && !max_heap.is_empty() && *max_heap.peek().unwrap() >= i as i32 {
                operations += 1;
                let end = max_heap.pop().unwrap() as usize;
                delta_array[end + 1] -= 1;
            }

            if operations < nums[i] {
                return -1;
            } 
        }

        return max_heap.len() as i32;
    }
}