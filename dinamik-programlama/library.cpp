#include <algorithm>
#include <cstdint>
#include <functional>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

namespace ieee_template {

namespace climbing_stairs {
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int prev = 2, prev2 = 1, res;
        for (int i = 3; i <= n; i++) {
            res = prev + prev2;
            prev2 = prev;
            prev = res;
        }
        return res;
    }
};
}

namespace min_cost_climbing_stairs {
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();
        for(int i = 2; i < n; i++) {
            cost[i] = min(cost[i] + cost[i-2], cost[i] + cost[i-1]);
        }

        return min(cost[n-1], cost[n-2]);
    }
};
}

}
