class Solution {
public:
    int m = 1000000007;
    long long pow2(long long n){
        if(n == 1) return 2;
        long long t = pow2(n/2);
        t = (t*t) % m;
        return (n%2)? (2*t)%m: t;
    }

    int monkeyMove(int n) {
        int t = pow2(n) - 2;
        return (t < 0)? m + t: t;
    }
};
