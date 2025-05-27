impl Solution {
    pub fn difference_of_sums(n: i32, m: i32) -> i32 {
        let mut answer: i32 = 0;

        answer  = (n * (n+1)) / 2;
        
        let mut x = m;
        
        while x <= n {
            answer -= 2*x;
            x+= m;
        }
        
        return answer;
    }
}