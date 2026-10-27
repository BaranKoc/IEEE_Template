class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        while(true) {
            bool largerThan1 = false;
            bool allzero = true;
            for(auto &n : nums) {
                if(n == 0) continue;
                allzero = false;
                if(n > 1) largerThan1 = true;
                ans += n % 2;
                n /= 2;
            }
            ans += largerThan1;
            if(allzero) break;
        }
        return ans;
    }
};
