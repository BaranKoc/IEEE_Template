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

namespace bit_counter {
class Solution {
public:
    int hammingWeight(uint32_t n) {
      int ans=0;
      while(n!=0){
        n=n&(n-1);
        ans++;
      }
      return ans;
    }
};
}

namespace single_number {
class Solution {
public:
    int singleNumber(vector<int>& nums) {
       unordered_map<int,int> a;
	   for(auto x: nums)
		   a[x]++;
	   for(auto z:a)
		   if(z.second==1)
			   return z.first;
	   return -1;
    }
};
}

}
