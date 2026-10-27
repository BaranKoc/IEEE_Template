class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int sol = 0, cnt = 0;

        for(int i = 0; i < nums.size(); i++ ) {

            if(cnt == 0){
                sol = nums[i];
                cnt = 1;
            }

            else if(sol == nums[i]){
                cnt++;
            }

            else{
                cnt--;
            }
        }

        return sol;
    }
};
