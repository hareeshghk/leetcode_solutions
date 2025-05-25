impl Solution {
    pub fn min(a: i32, b: i32) -> i32 {
        if a < b {
            return a;
        }
        return  b;
    }

    pub fn longest_palindrome(words: Vec<String>) -> i32 {
        // find pairs where pair is normal and its reverse.
        // if it doesnt have a pair then check if both chars are equal.

        let mut counter : Vec<i32> = vec![0; 676];
        let mut first = 0;
        let mut second = 0;
        for word in words {
            let mut chars = word.chars();
            if let Some(c1) = chars.next() {
                if let Some(c2) = chars.next() {
                    if c1.is_ascii_lowercase() && c2.is_ascii_lowercase() {
                        first = (c1 as u32) - ('a' as u32);
                        second = (c2 as u32) - ('a' as u32);

                        counter[(first * 26 + second) as usize] += 1;
                    }
                }
            }
        }

        let mut answer = 0;
        let mut found_extra = false;
        for i in 0..676 {
            first = i/26;
            second = i%26;

            if first > second {
                continue;
            }

            if first < second {
                answer += Self::min(counter[(first * 26 + second) as usize], counter[(second * 26 + first) as usize]) * 2;
            } else {
                answer += (counter[(first * 26 + second) as usize] / 2)*2;

                if counter[(first * 26 + second) as usize] % 2 != 0 {
                    found_extra = true;
                }
            }
        }

        if found_extra {
            answer += 1;
        }

        return answer * 2;
    }
}