class Solution {
public:

    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> answer;
        int current_number = 0;
        for(int i = 0; i < nums.size(); i++){
            current_binary = (current_number *2 + nums[i])%5;
            if(current_number == 0) answer.push_back(true);
            else answer.push_back(false);
        }
        return answer;
    }
};
