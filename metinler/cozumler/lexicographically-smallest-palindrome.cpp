class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while(l < r) {
            if(s[l] != s[r]) {
                char c = min(s[l], s[r]);
                s[l] = s[r] = c;
            }
            l++, r--;
        }
        return s;
    }
};
