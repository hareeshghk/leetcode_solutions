impl Solution {
    pub fn difference_of_sums(n: i32, m: i32) -> i32 {
        let mut answer: i32 = 0;
        
        for i in 1..=n {
            if  i % m != 0 {
                answer += i; 
            } else {
                answer -= i;
            }
       } 
       return answer;
    }
}