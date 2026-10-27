class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {

        int len = text.size();
        long long res = 0, aCount = 0, bCount = 0;
        char a = pattern[0], b = pattern[1];

        for (char c: text)  {
            if (c == a) aCount++;
            else if (c == b) bCount++;
        }

        if (a == b) return aCount++ * aCount / 2;

        if (aCount < bCount) res += bCount;
        else bCount++;

        for (char c: text)  {

            if (c == a) {
                res += bCount;
            }

            else if (c == b) bCount--;

        }
        return res;
    }
};
