impl Solution {
    pub fn difference_of_sums(n: i32, m: i32) -> i32 {
        let mut answer: i32 = 0;
        
        for i in 1..=n {
            answer += i;
       } 

       let mut x = m;

       while x <= n {
        answer -= 2*x;
        x+= m;
       }

       return answer;
    }
}