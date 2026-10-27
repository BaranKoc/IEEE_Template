class Solution {
public:
    string shortestPalindrome(string s) {

        int BASE = 26, MOD = 1e9+7;
        int start = s.size()-1;

        long front = 0, back = 0;
        long power = 1;

        for(int i=0; i<s.size(); i++){
            front = (front*BASE + (s[i]-'a'+1))%MOD;
            back = (back*BASE + (s[start--]-'a'+1))%MOD;
            power = (power*BASE)%MOD;
        }

        if(front == back){
            return s;
        }

        long new_front = 0, new_back = 0;
        long new_power = 1;

		int end=s.size()-1;
        string ans = "";

        while(end >= 0){

            int ch = (s[end]-'a'+1);

            new_front = (new_front*BASE + ch*power) % MOD;
            new_back = (ch*new_power + new_back) % MOD;
            new_power = (new_power*BASE) % MOD;

            int final_front = (new_front + front) % MOD;
			back = (back*BASE) % MOD;
            int final_back = (new_back + back) % MOD;

            ans += s[end];
            end--;

            if(final_front == final_back){
                break;
            }
        }
        return ans+s;
    }
};
