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

namespace sorted_search {
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int jump = 5;
        int p = 0;
        while (jump*5 < n) jump *= 5;
        while (jump > 0) {
            while (p+jump < n && nums[p+jump] <= target) p += jump;
            jump /= 5;
        }
        return (p == n || nums[p]!= target) ? -1 : p;
    }
};
}

}
