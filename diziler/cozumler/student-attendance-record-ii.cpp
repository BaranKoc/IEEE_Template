class Solution {
public:
    const int mod = 1e9 + 7;

    int add(int a, int b){
        return (a%mod + b%mod)%mod;
    }

    int sub(int a, int b){
        return (a%mod - b%mod + mod)%mod;
    }

    int mul(int a, int b){
        return (a%mod * 1ll * b%mod)%mod;
    }

    int checkRecord(int n) {
        if(n == 1) return 3;

        vector<int>PorL(n + 1);
        vector<int>P(n + 1);

        P[0] = 1, PorL[0] = 1;

        P[1] = 1;
        PorL[1] = 2;

        P[2] = PorL[1];
        PorL[2] = P[2] + P[1] + P[0];

        for(int i = 3;i<=n;i++){
            P[i] = PorL[i - 1] % mod;
            PorL[i] = add(P[i], add(P[i - 1], P[i - 2]));
        }

        int ans = PorL[n];

        for(int i = 1;i<=n;i++){

            int leftLength = i - 1;
            int rightLength = n - i;
            ans = add(ans, mul(PorL[leftLength], PorL[rightLength]));
        }
        return ans;

    }
};
