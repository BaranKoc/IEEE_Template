class Solution {
public:

    bool isScrambled(int s1_start, int s1_end, int s2_start, int s2_end,
                    string& s1, string& s2, unordered_map<string, bool>& dp) {

        string curr_cmb = to_string(s1_start) + ',' + to_string(s1_end) +
                            ',' + to_string(s2_start) + ',' + to_string(s2_end);

        auto it = dp.find(curr_cmb);
        if(it != dp.end())
            return dp[curr_cmb];

        if(s1_end < s1_start || s2_end < s2_start)
            return false;

        if(s1_end - s1_start != s2_end - s2_start)
            return false;

        if(s1.substr(s1_start, s1_end - s1_start + 1) == s2.substr(s2_start, s2_end - s2_start + 1))
            return true;

        vector<int> char_freq(256, 0);
        for(int i = 0; i <= s1_end - s1_start; i++)
            char_freq[s1[s1_start + i]-'a']++, char_freq[s2[s2_start + i]-'a']--;
        for(int i = 0; i < 256; i++)
            if(char_freq[i])
				return false;

        for(int k = 0; k < (s1_end - s1_start); k++) {

            if(isScrambled(s1_start, s1_start + k, s2_start, s2_start + k, s1, s2, dp)  &&
              isScrambled(s1_start + k + 1, s1_end, s2_start + k + 1, s2_end, s1, s2, dp))
                return dp[curr_cmb] = true;

            if(isScrambled(s1_start, s1_start + k, s2_end - k, s2_end, s1, s2, dp)  &&
              isScrambled(s1_start + k + 1, s1_end, s2_start, s2_end - k - 1, s1, s2, dp))
                return dp[curr_cmb] = true;
        }
        return dp[curr_cmb] = false;
    }

    bool isScramble(string s1, string s2) {

        unordered_map<string, bool> dp;
        return isScrambled(0, s1.size()-1, 0, s2.size()-1, s1, s2, dp);
    }
};
