class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {

        vector<int> left(2,0);
        vector<int> right(2,0);

        int ans=0;

        for(int i=0;i<nums.size();i++)
        {
            if(i%2)
            {

                right[1]+=nums[i];
            }
            else{

                right[0]+=nums[i];
            }
        }

        for(int i=0;i<nums.size();i++)
        {

            int currOdd=right[1];
            int currEven=right[0];
            if(i%2)
            {

                currOdd-=nums[i];
                right[1]-=nums[i];
            }
            else{

                currEven-=nums[i];
                right[0]-=nums[i];
            }

            if(left[0]+currOdd==left[1]+currEven)
                ans++;

            (i%2) ? left[1]+=nums[i] : left[0]+=nums[i];
        }

        return ans;
    }
};
