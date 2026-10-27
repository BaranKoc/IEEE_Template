#define ll long long
class Solution {
public:
    vector<vector<ll> > dp;
    ll mod = 1e9 + 7;

    ll numWays(ll n, ll k) {
        if(k == 0 || k > n) return 0;
        if(n <= 2) return 1;

        if(dp[n][k] != -1) return dp[n][k];

        ll ans = 0;

        ans = (ans + numWays(n - 1, k - 1)) % mod;

        ans = (ans + ((n - 1) * numWays(n - 1, k))) % mod;

        return dp[n][k] = ans;
    }

    int rearrangeSticks(int n, int k) {
        dp = vector<vector<ll> >(n + 1, vector<ll>(k + 1, -1));
        return numWays(n, k);
    }
};
