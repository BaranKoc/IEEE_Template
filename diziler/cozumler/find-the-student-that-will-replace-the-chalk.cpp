class Solution {
public:

    int chalkReplacer(vector<int>& chalk, int k) {

        int n = chalk.size();

        long sum = 0;

        for (int n : chalk) sum += n;

        k = k % sum;

        int idx = 0;

        while (k >= chalk[idx]) {

            k -= chalk[idx];

            idx = (idx + 1) % n;
        }

        return idx;
    }
};
