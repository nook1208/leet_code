#include <iostream>
using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        int one_cnt = 0;
        int segment_cnt = 0;

        for (int i = 0; i < s.size(); i++) {            
            if (s[i] == '0') {
                if (one_cnt)
                    segment_cnt++;
                one_cnt = 0;
            } else {
                one_cnt++;
            }
        }

        if (one_cnt)
            segment_cnt++;

        return (segment_cnt == 1) ? true : false;
    }
};
