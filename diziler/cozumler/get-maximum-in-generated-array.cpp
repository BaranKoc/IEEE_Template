class Solution {
public:
    int getMaximumGenerated(int n) {

        if (n < 2) return n;

        int arr[n + 1], m;
        arr[0] = 0, arr[1] = 1;

        for (int i = 2; i <= n; i++) {
            if (i % 2) arr[i] = arr[i / 2] + arr[i / 2 + 1];
            else arr[i] = arr[i / 2];

            m = max(arr[i], m);
        }
        return m;
    }
};
