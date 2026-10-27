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

namespace min_subarray_window {
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int m=INT_MAX,s=0,l=0;
        for(int i=0;i<nums.size();i++)
        {
            s+=nums[i];
            if(s>=target)
                m=min(m,i-l+1);
            while(s>=target)
            {
                m=min(m,i-l+1);
                s-=nums[l++];
            }
        }
        if(m==INT_MAX)
            m=0;
        return m;
    }
};
}

}
