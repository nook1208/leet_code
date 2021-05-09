#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    double inline get_diff(double pass, double total) {
        return (pass + 1) / (total + 1) - pass / total;
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double total_pass_ratio = 0;
        priority_queue<pair<double, array<int, 2>>> diffs;       

        for (auto &i : classes) {
            double pass_ratio = (double) i[0] / i[1];
            diffs.push({ get_diff(i[0], i[1]), {i[0], i[1]} });

            total_pass_ratio += pass_ratio;
        }

        for (int i = 0; i < extraStudents; i++) {
            auto class_info = diffs.top().second;
            total_pass_ratio += diffs.top().first;
            diffs.pop();

            diffs.push({ get_diff(class_info[0] + 1, class_info[1] + 1), { class_info[0] + 1, class_info[1] + 1} });
        }

        return total_pass_ratio / classes.size();
    }
};
