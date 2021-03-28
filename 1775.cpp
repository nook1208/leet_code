#include <iostream>
#include <vector>
using namespace std;

#define MIN(a, b) (((a) <= (b)) ? (a) : (b))

class Solution {
public:
    int val_num[10] = {}, diff = 0;

    typedef struct arr_info {
        int nums[10];
        int total;
    } arr_info;

    void set_nums(arr_info smaller, arr_info bigger) {
        for (int val = 1; val <= 6; val++) {
            diff = bigger.total - smaller.total;
            for (int i = 1; val + i <= 6; i++)
                val_num[i] += smaller.nums[val];
            
            for (int i = 1; i < val; i++)
                val_num[i] += bigger.nums[val];
        }
    }    

    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        arr_info a = {};
        arr_info b = {};
        
        int ret = 0;

        for (auto i : nums1) {
            a.total += i;
            a.nums[i]++;
        }

        for (auto i : nums2) {
            b.total += i;
            b.nums[i]++;
        }

        if (a.total < b.total)
            set_nums(a, b);        
        else
            set_nums(b, a);

        for (int i = 5; i > 0; i--) {         
            if (!diff)
                return ret;

            int val = diff / i;
            int cnt = MIN(val, val_num[i]);
            
            for (int j = i; j > 0; j--)
                val_num[j] -= cnt;
            
            diff -= i * cnt;
            ret += cnt;
        }

        return (diff) ? -1 : ret;
    }
};
