impl Solution {
    pub fn find_words_containing(words: Vec<String>, x: char) -> Vec<i32> {
        let mut answer = Vec::new();
        for i in 0..words.len() {
            for c in words[i].chars() {
                if c == x {
                    answer.push(i as i32);
                    break;
                }
            }
        }

        return answer; 
    }
}