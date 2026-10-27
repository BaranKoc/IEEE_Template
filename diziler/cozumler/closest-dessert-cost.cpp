class Solution {
public:

    int ans=INT_MAX,mn=INT_MAX;

    void find(int i,vector<int>& tc,int curr, int tar)
    {

        if(abs(curr-tar)<mn)
        {
            mn=abs(curr-tar);
            ans=curr;
        }

        if(abs(curr-tar)==mn) ans=min(ans,curr);

        if(i>=tc.size() || curr-tar>mn) return;

         find(i+1,tc,curr+tc[i],tar);

         find(i+1,tc,curr+2*tc[i],tar);

         find(i+1,tc,curr,tar);

    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {

        for(auto x:baseCosts)
        {

            find(0,toppingCosts,x,target);
        }

        return ans;

    }
};
