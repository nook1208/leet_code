#include <iostream>
using namespace std;

class Solution {
public:
    bool str_equal(string s1, string s2) {
        for (int i = 0; i < s1.size(); i++)
            if (s1[i] != s2[i])
                return false;
        return true;
    }

    void str_swap(string& str, int a, int b) {
        char temp;
        temp = str[a];
        str[a] = str[b];
        str[b] = temp;
    }

    bool areAlmostEqual(string s1, string s2) {
        for (int a = 0; a < s1.size(); a++) {
            for (int b = a; b < s1.size(); b++) {
                str_swap(s2, a, b);                                
                if (str_equal(s1, s2))
                    return true;
                else
                    str_swap(s2, a, b);                            
            }
        }

        return false;
    }
};

