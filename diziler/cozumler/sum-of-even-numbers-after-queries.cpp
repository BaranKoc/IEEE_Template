class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        int tes=accumulate(nums.begin(),nums.end(),0,[](int curr,int a) {if(a%2==0) return curr+=a;
                else return curr;});
        vector<int> ans(queries.size());
        bool a=false,b=false;
        for(int i=0;i<queries.size();i++)
        {

            a=nums[queries[i][1]]%2==0 && queries[i][0]%2==0;
            b=abs(nums[queries[i][1]]%2)==1 && abs(queries[i][0]%2)==1;
            if(a)
                tes+=queries[i][0];
            else if(b)
                tes+=queries[i][0]+nums[queries[i][1]];
            else if(nums[queries[i][1]]%2==0)
                tes-=nums[queries[i][1]];
            ans[i]=tes;
            nums[queries[i][1]]+=queries[i][0];
        }
        return ans;
    }
};
