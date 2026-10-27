class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

        int max_grumpy_window = 0, grumpy_window = 0;
        int curr = 0, n = customers.size();

        int satisfied_cx = 0;

        minutes = min(minutes, n);

        while(curr < minutes) {
            satisfied_cx += (!grumpy[curr] ? customers[curr] : 0);
            grumpy_window += (grumpy[curr] ? customers[curr] : 0);
            ++curr;
        }

        max_grumpy_window = max(max_grumpy_window, grumpy_window);

        while(curr < n) {

            grumpy_window -= (grumpy[curr - minutes] ? customers[curr - minutes] : 0);

            grumpy_window += (grumpy[curr] ? customers[curr] : 0);
            max_grumpy_window = max(max_grumpy_window, grumpy_window);

            satisfied_cx += (!grumpy[curr] ? customers[curr] : 0);
            ++curr;
        }

        return satisfied_cx + max_grumpy_window;
    }
};
