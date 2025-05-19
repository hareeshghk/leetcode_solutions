impl Solution {
    pub fn triangle_type(nums: Vec<i32>) -> String {
        let a = nums[0];
        let b = nums[1];
        let c = nums[2];

        if a+b <= c || b+c <= a || c+a <= b {
            return "none".to_string();
        }

        if a!=b && b!=c && c!= a {
            return "scalene".to_string();
        }

        if a == b && b == c {
            return "equilateral".to_string();
        }

        return "isosceles".to_string();

    }
}