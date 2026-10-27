class Solution:

    def isIsomorphic(self, s: str, t: str) -> bool:
        dict1 = {}
        m = ''
        for i, j in zip(s, t):
            if j in dict1.values() and i not in dict1.keys():
                return False
            dict1[i] = j
        for k in s:
            m = m + dict1[k]
        if m == t:
            return True
        else:
            return False
