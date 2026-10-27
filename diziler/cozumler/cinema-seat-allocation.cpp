class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> o;

        for (auto r : reservedSeats) {

            o[r[0]].push_back(r[1]);
        }

        int ans = 2 * (n - o.size());

        for (auto p : o) {

            vector<int> seats = p.second;

            int occupied_mask = 0;

            for (int s : seats) {
                if (s > 1 && s < 10) {
                    occupied_mask += (int)pow(2, 10 - s);
                }
            }

            int masks[3] = {480, 120, 30};

            int row_ans = 0;
            bool res1 = (masks[0] & occupied_mask) == 0;
            bool res2 = (masks[1] & occupied_mask) == 0;
            bool res3 = (masks[2] & occupied_mask) == 0;

            if (res1 && res2 && res3) row_ans += 2;
            else if (res1 || res2 || res3) row_ans += 1;

            ans += row_ans;

        }

        return ans;
    }
};
