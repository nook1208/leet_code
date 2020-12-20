impl Solution {
    pub fn array_strings_are_equal(word1: Vec<String>, word2: Vec<String>) -> bool {
        let mut w1 = String::new();
        let mut w2 = String::new();


        for s1 in word1 {
            w1.push_str(s1.as_str());
        }

        for s2 in word2 {
            w2.push_str(s2.as_str());
        }

        w1.len() == w2.len() && w1 == w2
    }
    
}
