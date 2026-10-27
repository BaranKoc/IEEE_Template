class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp1,mp2;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int c=nums[i];
            mp1[c]++;
            mp2[mp1[c]]++;
            if(i!=n-1 && mp2[mp1[c]]*mp1[c]==i+1)

                ans=i+2;
            if(mp2[mp1[c]]*mp1[c]==i)

                ans=i+1;
        }
        return ans;
    }
};
