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

namespace subset_enumerator {
class Solution {
public:
    vector<vector<int>> ans;

    void sub(vector<int> &nums, int i, vector<int> temp)
    {
        if(i==nums.size())
        {
            ans.push_back(temp);
            return;
        }

        sub(nums, i+1, temp);
        temp.push_back(nums[i]);
        sub(nums, i+1, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        sub(nums, 0, temp);
        return ans;
    }
};
}

}
