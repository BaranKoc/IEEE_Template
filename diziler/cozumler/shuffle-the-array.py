class Solution:

    def shuffle(self, nums: List[int], n: int) -> List[int]:
        return [number for tup in zip(nums[:n], nums[n:]) for number in tup]
