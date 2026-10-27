class Solution:

    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        n, m = (len(target), len(arr))
        if m > n:
            return False
        t = Counter(target)
        a = Counter(arr)
        for k, v in a.items():
            if k in t and v == t[k]:
                continue
            else:
                return False
        return True
