#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int edge_cnt[100005] = {};

    int findCenter(vector<vector<int>>& edges) {           

        for (int i = 0; i < edges.size(); i++) 
            for (int j = 0; j < 2; j++)                
                if (++edge_cnt[edges[i][j]] == edges.size())
                    return edges[i][j];

        return 0;
    }
};
