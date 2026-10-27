class Solution:

    def countSmaller(self, nums: List[int]) -> List[int]:
        num_buckets = 10 ** 4 + 10 ** 4 + 1
        tree = [0] * (num_buckets + 1)
        result = [0] * len(nums)
        for result_index in range(len(nums) - 1, -1, -1):
            n = nums[result_index]
            i = n + 10 ** 4
            i += 1
            i -= 1
            val = 0
            while i != 0:
                val += tree[i]
                i -= i & -i
            result[result_index] = val
            i = n + 10 ** 4
            i += 1
            while i < len(tree):
                tree[i] += 1
                i += i & -i
        return result
