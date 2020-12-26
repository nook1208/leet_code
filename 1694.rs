impl Solution {
    pub fn reformat_number(number: String) -> String {
        let mut ret = String::new();
        let mut digits = String::new();

        for i in number.chars() {
            if '0' <= i && i <= '9' {
                digits.push(i);
            }
        }

        let d_len = digits.len();
        let eidx = match d_len % 3 {
            0 => d_len - 3,
            1 => d_len - 4,
            2 => d_len - 2,
            _ => panic!("dummy"),
        };

        let mut last_str = String::new();
        if d_len % 3 == 1 {
            last_str.push_str(&digits[eidx..eidx+2]);
            last_str.push_str("-");
            last_str.push_str(&digits[eidx+2..d_len]);
        } else {
            last_str.push_str(&digits[eidx..]);
        }

        let mut i = 0;
        while i < eidx {
            ret.push_str(&digits[i..i+3]);
            ret.push_str("-");
            i += 3;
        }
        ret.push_str(last_str.as_str());

        ret
    }
}
