class Solution:

    def partition(self, s: str) -> List[List[str]]:
        lookup = {'': [[]]}

        def lps(s):
            if s in lookup:
                return lookup[s]
            final_res = []
            result_set = set()
            for k in range(len(s)):
                i, j = (k, k)
                while i >= 0 and j < len(s) and (s[i] == s[j]):
                    res = []
                    for partition in lps(s[:i]):
                        res.append(partition + [s[i:j + 1]])
                    for partition in res:
                        for part in lps(s[j + 1:]):
                            temp = partition + part
                            if tuple(temp) not in result_set:
                                result_set.add(tuple(temp))
                                final_res.append(temp)
                    i -= 1
                    j += 1
                i, j = (k, k + 1)
                while i >= 0 and j < len(s) and (s[i] == s[j]):
                    res = []
                    for partition in lps(s[:i]):
                        res.append(partition + [s[i:j + 1]])
                    for partition in res:
                        for part in lps(s[j + 1:]):
                            temp = partition + part
                            if tuple(temp) not in result_set:
                                result_set.add(tuple(temp))
                                final_res.append(temp)
                    i -= 1
                    j += 1
            lookup[s] = final_res
            return final_res
        return lps(s)
