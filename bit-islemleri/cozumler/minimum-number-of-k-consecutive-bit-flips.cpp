class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {

        int n = nums.size();

        int flips = 0;
        vector<int> flip(n+1,0);
        int ops = 0;

        for(int i=0;i<n;i++){

            flips +=flip[i];

            if(nums[i]==1 && (flips)%2==0){
                continue;
            }

            if(nums[i]==0 && (flips)%2!=0){
                continue;
            }

            if(i+k > n){
                return -1;
            }

            ops++;
            flips++;
            flip[i+k] = -1;

        }

        return ops;

    }
};
