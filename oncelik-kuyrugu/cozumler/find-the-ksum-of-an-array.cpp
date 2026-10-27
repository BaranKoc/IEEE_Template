class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long maxsum = 0;

        vector<long long> subtract;

        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                maxsum+=nums[i];
            }else{
                nums[i] = abs(nums[i]);
            }
        }

        sort(nums.begin(), nums.end());

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

        pq.push({nums[0], 0});
        while(!pq.empty() && subtract.size()<k-1){
            pair<long long,int> topp = pq.top();
            pq.pop();
            long long subt = topp.first;
            int idx = topp.second;

            subtract.push_back(subt);

            if(idx<n-1){
                pq.push({subt+nums[idx+1] , idx+1});
                pq.push({nums[idx+1] + (subt-nums[idx]) , idx+1});
            }
        }

        vector<long long>ans;
        ans.push_back(maxsum);
        for(long long subt:subtract) {
            ans.push_back(maxsum - subt);
        }

        return ans[k-1];
    }
};
