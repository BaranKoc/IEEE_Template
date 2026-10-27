class Solution(object):

    def isScramble(self, s1, s2):
        if s1 == s2:
            return True
        if len(s1) != len(s2):
            return False
        count1 = collections.defaultdict(int)
        count2 = collections.defaultdict(int)
        for c1, c2 in zip(s1, s2):
            count1[c1] += 1
            count2[c2] += 1
        if count1 != count2:
            return False
        lcount1 = collections.defaultdict(int)
        lcount2 = collections.defaultdict(int)
        rcount2 = collections.defaultdict(int)
        for i in xrange(len(s1) - 1):
            lcount1[s1[i]] += 1
            lcount2[s2[i]] += 1
            rcount2[s2[len(s1) - 1 - i]] += 1
            if lcount1 == lcount2:
                if self.isScramble(s1[:i + 1], s2[:i + 1]) and self.isScramble(s1[i + 1:], s2[i + 1:]):
                    return True
            elif lcount1 == rcount2:
                if self.isScramble(s1[:i + 1], s2[-(i + 1):]) and self.isScramble(s1[i + 1:], s2[:-(i + 1)]):
                    return True
        return False
