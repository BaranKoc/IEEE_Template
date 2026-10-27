class Solution {
public:
    using pi = pair<int, int>;
    int totalSteps(vector<int>& nums) {
        int N = nums.size();
        map<int, int> mp;
        vector<pi> del;
        for (int i = 0; i < N; ++i) {
            mp[i] = nums[i];
            if (i+1 < N && nums[i] > nums[i+1])
                del.emplace_back(i, i+1);
        }

        int ans = 0;
        while (!del.empty()) {
            ++ans;
            vector<pi> nxt;
            for (auto [i,j] : del) mp.erase(j);
            for (auto [i,j] : del) {
                auto it = mp.find(i);
                if ( it == end(mp) || next(it) == end(mp) )
                    continue;
                auto itn = next(it);
                if (it->second > itn->second)
                    nxt.emplace_back(it->first, itn->first);
            }
            swap(nxt, del);
        }
        return ans;

    }
};
