class Solution(object):

    def wordPattern(self, pattern, s):
        p, s = (list(pattern), list(s.split(' ')))
        return len(s) == len(p) and len(set(zip(p, s))) == len(set(s)) == len(set(p))
