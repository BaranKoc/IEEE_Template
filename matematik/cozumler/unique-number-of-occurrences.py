class Solution:

    def uniqueOccurrences(self, arr: List[int]) -> bool:
        occ = dict()
        for element in arr:
            if element not in occ:
                occ[element] = 0
            else:
                occ[element] += 1
        values = list(occ.values())
        unique = set(values)
        if len(values) == len(unique):
            return True
        else:
            return False
