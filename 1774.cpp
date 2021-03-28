#include <iostream>
#include <vector>
using namespace std;

#define MIN(a, b) (((a) <= (b)) ? (a) : (b))
    
class Solution {
public:
    int get_absolute_val(int a, int b) {
        int ret = a - b;
        if (ret < 0)
            return ret * -1;
        return ret;
    }

    int get_closest_cost(int my_cost, int new_cost, int target) {
        int my_diff = get_absolute_val(target,my_cost);
        int new_diff = get_absolute_val(target, new_cost);

        if (my_diff == new_diff)
            return MIN(my_cost, new_cost);
        return (my_diff < new_diff) ? my_cost : new_cost;
    }

    int get_closest_topping_cost(int n, int target, vector<int>& top_costs) {
        int my_cost = 10000000;
        
        if (top_costs.size() <= n)
            return 0;

        for (int cnt = 0; cnt < 3; cnt++) {
            int top_cost = top_costs[n] * cnt;
            int new_cost = top_cost + get_closest_topping_cost(n + 1, target - top_cost, top_costs);
            my_cost = get_closest_cost(my_cost, new_cost, target);
        }

        return my_cost;
    }

    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int ret = 10000000;

        for (int i = 0; i < baseCosts.size(); i++) {
            int new_cost = baseCosts[i] + get_closest_topping_cost(0, target - baseCosts[i], toppingCosts);
            ret = get_closest_cost(ret, new_cost, target);
        }

        return ret;
    }
};
