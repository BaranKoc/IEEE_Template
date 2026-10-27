class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        long long ans = 0;
        int n = flowers.size();
        if(n == 0) return 0;
        sort(flowers.begin(), flowers.end());
        vector<long long> pref(n, 0);
        pref[0] = flowers[0];
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + flowers[i];
        }
        for(int i = n; i >= 0; i--) {

            if(i < n) {
                long long toAdd = max(0, target - flowers[i]);
                if(newFlowers < toAdd) {
                    break;
                }
                newFlowers -= toAdd;
                flowers.pop_back();
            }
            long long beautyForFullCase = (long long)(n - i) * full;

            int l = 0, r = target - 1;
            long long beautyForPartialCase = 0;
            while(l <= r) {
                long long mid = l + (r - l) / 2;
                auto it = upper_bound(flowers.begin(), flowers.end(), mid);
                if(it == flowers.begin()) {
                    l = mid + 1;
                } else {
                    long long len = distance(flowers.begin(), it);
                    long long sum = pref[len - 1];
                    long long needed = ((long long)mid * len) - sum;
                    if(needed <= newFlowers) {
                        l = mid + 1;
                        beautyForPartialCase = (long long)mid * partial;
                    } else {
                        r = mid - 1;
                    }
                }
            }
            ans = max(ans, beautyForFullCase + beautyForPartialCase);
        }
        return ans;
    }
};
