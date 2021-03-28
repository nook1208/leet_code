#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ret = 0;
        
        for (int i = 0; i < items.size(); i++) {
            switch (ruleKey[0]) {
            case 't':
                if (items[i][0].compare(ruleValue) == 0)
                    ++ret;
                break;
            case 'c':
                if (items[i][1].compare(ruleValue) == 0)
                    ++ret;
                break;
            case 'n':
                if (items[i][2].compare(ruleValue) == 0)
                    ++ret;
                break;
            }
        }
        return ret;
    }
};
