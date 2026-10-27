class Solution {
private:
    const int MOD = 1000000007;

    long long power(long long x, long long y)
    {
        if (y == 0)
            return 1;
        long long ans = power(x, y / 2);
        if (y % 2 == 0)
            return (ans * ans) % MOD;
        else
            return (((ans * ans) % MOD) * (x % MOD)) % MOD;
    }

public:
    int minNonZeroProduct(int p) {
        long long max_i = pow(2, p);
        long long max = max_i - 1;
        long long result = power((max - 1), ((max - 1) / 2));
        return (result * (max % MOD)) % MOD;
    }
};
