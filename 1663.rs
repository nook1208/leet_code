// ascii value of 'a' - 1
const ASCII_VAL: u8 = 96;
const MAX_VAL: i32 = 26;

impl Solution {
    pub fn get_smallest_string(n: i32, k: i32) -> String {
		let mut s = String::with_capacity(n as usize);
        let mut total_val = k;
        let mut cur_val = 1;

        for i in 1..n+1 {
            let possible_max_val = (n-i) * MAX_VAL;
            let remaining_val = total_val - cur_val;

            if possible_max_val < remaining_val {
                cur_val += remaining_val - possible_max_val;
            }

            total_val -= cur_val;
            s.push((cur_val as u8 + ASCII_VAL) as char);
        }

        s
    }
}

