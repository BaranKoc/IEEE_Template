class Solution {
public:
bool checkPossibility(vector<int>& nums) {
    if(nums.size()<=2)
        return true;

    vector<int>diff(nums.size()-1);
    int neg=0;

    for(int i=0;i<nums.size()-1;i++)
    {
        diff[i]=nums[i+1]-nums[i];
        diff[i]<0?neg++:0;
    }

    if(neg>1)
        return false;

    for(int i=0;i<diff.size();i++)
    {
        if(diff[i]<0 and i!=diff.size()-1)
        {
            if(i==0)

                continue;

            if((nums[i-1]<=nums[i+1]) || (diff[i+1])>=abs(diff[i]))
                continue;
            else
                return false;
        }
    }
    return true;
}
