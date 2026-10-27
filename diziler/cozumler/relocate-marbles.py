class Solution:

    def relocateMarbles(self, nums: List[int], moveFrom: List[int], moveTo: List[int]) -> List[int]:
        s = set(nums)
        for f, t in zip(moveFrom, moveTo):
            s.remove(f)
            s.add(t)
        return sorted(s)
