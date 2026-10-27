class Solution {
public:

    bool isPossible(int cp, vector<int>& weights, int days)
    {
        int d = 1;
        int cw = 0;

        for (auto x : weights) {
            if (x + cw <= cp) {

                cw += x;
            } else {

                d++;
                cw = x;
                if (x > cp) {

                    return false;
                }
            }
        }

        return d <= days;
    }

    int shipWithinDays(vector<int>& weights, int days)
    {

        int s = 1;
        int e = 1E9;
        int ans = -1;

        while (s <= e) {

            int mid = (s + e) / 2;

            bool ok = isPossible(mid, weights, days);

            if (ok) {
                ans = mid;
                e = mid - 1;
            } else {

                s = mid + 1;
            }
        }

        return ans;
    }
};
