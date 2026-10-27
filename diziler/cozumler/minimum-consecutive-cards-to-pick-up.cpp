class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {

        int res (INT_MAX), n(size(cards));
        unordered_map<int, int> m;
        for (auto i=0; i<n; i++) {

            if (m.count(cards[i])) res = min(res, i-m[cards[i]]+1);
            m[cards[i]] = i;
        }
        return (res == INT_MAX) ? -1 : res;
    }
};
