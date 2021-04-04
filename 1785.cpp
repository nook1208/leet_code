#include <iostream>
#include <vector>
using namespace std;

typedef long long int i64;

class Solution {
public:

    i64 inline abs(i64 val) {
        return (val < 0) ? (i64) val * -1 : val;
    }
   
    int minElements(vector<int>& nums, i64 limit, i64 g) {        
        for (int i = 0; i < nums.size(); i++)
            g -= nums[i];

        int ret = abs(g) / limit;
        if (abs(g) % limit) ret++;

        return ret;
    }
};
