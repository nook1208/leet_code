class Solution {
public:
    int get_subsets_xor(vector<int>& nums, vector<int>& targets, int idx, int max_cnt) {
        int total_xor = 0;

        if (max_cnt == targets.size()) {
            int sum_xor = targets[0];
            for (int i = 1; i < targets.size(); i++)
                sum_xor ^= targets[i];
            return sum_xor;
        }

        if (nums.size() == idx)
            return 0;
            
        total_xor += get_subsets_xor(nums, targets, idx + 1, max_cnt);

        targets.push_back(nums[idx]);
        total_xor += get_subsets_xor(nums, targets, idx + 1, max_cnt);
        targets.pop_back();
        
        return total_xor;
    }
    
    int subsetXORSum(vector<int>& nums) {
        int ret = 0;
        for (int i = 1; i <= nums.size(); i++) {            
            vector<int> targets;
            ret += get_subsets_xor(nums, targets, 0, i);                   
        }

        return ret;
    }
};
