class Solution:

    def longestAwesome(self, s: str) -> int:
        li = [2 ** i for i in range(10)]
        checker = set(li)
        checker.add(0)
        di = collections.OrderedDict({0: -1})
        maxLength = prefix_xor = 0
        for i in range(len(s)):
            prefix_xor ^= li[int(s[i])]
            if prefix_xor not in di:
                di[prefix_xor] = i
            for key in di.keys():
                if i - di[key] <= maxLength:
                    break
                if key ^ prefix_xor in checker:
                    maxLength = i - di[key]
        return maxLength
