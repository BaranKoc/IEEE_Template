class Solution {
public:
    int uniqueChars(string& s) {
        unordered_set<char> chars(s.begin(), s.end());
        return chars.size();
    }

    int longestSubstring(string s, int k) {

        int max_unique_chars = uniqueChars(s);
        int max_len = 0, n = s.size();

        for(int curr_unique_chars = 1; curr_unique_chars <= max_unique_chars; curr_unique_chars++) {
            int start = 0, end = 0;
            int atleast_k = 0;
            unordered_map<char, int> freq;

            while(end < n) {

                if(++freq[s[end]] == k)
                    ++atleast_k;
                ++end;

                while(freq.size() > curr_unique_chars && start <= end) {

                    if(freq[s[start]] == k)
                        --atleast_k;
                    if(--freq[s[start]] == 0)
                        freq.erase(s[start]);
                    ++start;
                }

                if(freq.size() == curr_unique_chars && atleast_k == freq.size())
                    max_len = max(max_len, end - start);
            }
        }
        return max_len;
    }
};
