#define ll long long
class Solution {
public:

    ll numDecodings(string s) {

        ll M = 1000000007;
        ll dp[s.size() + 1];
        memset(dp, 0, sizeof(dp));

        dp[0] = 1;

        for(int i = 1; i <= s.size(); i++){
            if(s[i - 1] == '*' and i == 1)
                dp[i] = 9;
            else if(s[i - 1] == '0' and i == 1)
                dp[i] = 0;
            else if(i == 1)
                dp[i] = 1;
            else{

                if(s[i - 1] == '*')
                    dp[i] += (9 * dp[i - 1]) % M;
                else{
                    if(s[i - 1] == '0')
                        dp[i] = 0;
                    else
                        dp[i] += dp[i - 1] % M;
                }

                if(s[i - 2] == '*'){
                    if(s[i - 1] == '*')
                        dp[i] += (15 * dp[i - 2]) % M;
                    else if(s[i - 1] > '6')
                        dp[i] += dp[i - 2] % M;
                    else
                        dp[i] += (2 * dp[i - 2]) % M;

                }
                else if(s[i - 2] == '1'){
                    if(s[i - 1] == '*'){
                        dp[i] += (9 * dp[i - 2]) % M;
                    }
                    else
                        dp[i] += dp[i - 2] % M;

                }
                else if(s[i - 2] == '2'){
                    if(s[i - 1] == '*')
                        dp[i] += (6 * dp[i - 2]) % M;
                    else if(s[i - 1] <= '6')
                        dp[i] += dp[i - 2] % M;
                }
            }
        }

        return dp[s.size()] % M;
    }
};
