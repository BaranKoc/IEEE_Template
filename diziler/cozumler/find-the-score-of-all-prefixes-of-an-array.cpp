class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> b;
        vector<long long> ans;
        int n = nums.size();
        int mm= INT_MIN;
        long long aa = 0;
        for(int  i = 0 ; i < n; i++){
            long long a  = 0;
            mm = max(mm, nums[i]);
            a = nums[i] + mm;
            b.push_back(a);
            aa += b[i];
            ans.push_back(aa);
        }
        return ans;
    }
};
