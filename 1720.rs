impl Solution {
    pub fn decode(encoded: Vec<i32>, first: i32) -> Vec<i32> {
        let mut ret: Vec<i32> = vec![first];

        for i in 0..encoded.len() {
            ret.push(ret[i] ^ encoded[i]);
        }

        ret
    }
}