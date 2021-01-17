impl Solution {
    pub fn interpret(command: String) -> String {
        let mut ret = String::new();
        let mut cnt = 0;
        for i in command.chars() {
            if i == 'G' {
                ret += "G";
                continue;
            }

            if i == '(' {
                cnt = 1;
            } else if i == ')' {
                match cnt {
                    1 => ret += "o",
                    _ => ret += "al",
                }
            } else {
                cnt += 1;
            }
        }

        ret
    }
}
