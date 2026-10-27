class Solution(object):

    def minMovesToMakePalindrome(self, s):
        count, length_of_s = (0, len(s))
        if length_of_s <= 2:
            return count
        for i in reversed(range(length_of_s)):
            if s[i] != s[0]:
                continue
            if i == 0:
                count += len(s) / 2 + self.minMovesToMakePalindrome(s[1:])
            else:
                count += len(s) - 1 - i + self.minMovesToMakePalindrome(s[1:i] + s[i + 1:])
            break
        return count
