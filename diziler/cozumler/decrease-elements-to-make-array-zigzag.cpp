class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int even = 0, odd = 0;

		if (nums.size() <= 1) return 0;

        for (int i = 0; i < nums.size(); i+= 2) {
			if (i == 0) {
				if (nums[i] >= nums[i+1]) even += nums[i]-nums[i+1]+1;
			} else if (i == nums.size() - 1) {
				if (nums[i-1] <= nums[i]) even += nums[i]-nums[i-1]+1;
			} else {
				if (nums[i-1] <= nums[i] || nums[i+1] <= nums[i]) {
					even += nums[i] - min(nums[i-1], nums[i+1]) + 1;
				}
			}
		}

		for (int i = 1; i < nums.size(); i += 2) {
			if (i == nums.size() - 1) {
				if (nums[i-1] <= nums[i]) odd += nums[i]-nums[i-1]+1;
			} else {
				if (nums[i-1] <= nums[i] || nums[i+1] <= nums[i]) {
					odd += nums[i] - min(nums[i-1], nums[i+1]) + 1;
				}
			}
		}

		return min(even, odd);
    }
};
