class Solution:

    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
        d = defaultdict(int)
        counter = defaultdict(int)
        r = l = 0
        while r < len(s):
            counter[s[r]] += 1
            while r - l + 1 > minSize:
                counter[s[l]] -= 1
                if counter[s[l]] == 0:
                    del counter[s[l]]
                l += 1
            if r - l + 1 == minSize and len(counter) <= maxLetters:
                d[s[l:r + 1]] += 1
            r += 1
        return max(d.values()) if d else 0
