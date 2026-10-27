class Solution {
public:
    int hammingDistance(int x, int y) {
        int XOR=x^y;

        int count=0;
        while(XOR){
            if(XOR&1)
                count++;

            XOR=XOR>>1;
        }
        return count;
    }

    int totalHammingDistance(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                ans+=hammingDistance(nums[i],nums[j]);
            }
        }

        return ans;
    }
};
