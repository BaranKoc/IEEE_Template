class Solution {
public:
  int mod=1e9+7;
  int minimumPossibleSum(long long n, long long target) {

    long long ans = 0;

    long long below_target=target/2;

    if(n<=below_target) return (n*(n+1))/2;

    ans+=((below_target*(below_target+1))/2);

    n-=(below_target);

    n+=(target-1);

    ans+=((n*(n+1))/2)-(((target-1)*target)/2);

    return ans%mod;
  }
};
