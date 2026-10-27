class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int ans = INT_MAX;
        vector<int> v(value, 0);
        for(auto n: nums) v[((n % value)+value) %value]++;
        for(int i = 0; i < v.size(); i++) {
            if(v[i] == 0) return i;
            ans = min(ans, value*v[i] + i);
        }
        return ans;
    }
};
