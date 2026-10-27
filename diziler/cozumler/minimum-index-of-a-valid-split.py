class Solution:

    def minimumIndex(self, nums: List[int]) -> int:
        n = len(nums)

        def most_frequent(data):
            counter = Counter(data)
            max_count = -1
            max_item = None
            for item, count in counter.items():
                if count > max_count:
                    max_count = count
                    max_item = item
            return (max_item, max_count)
        dom, cnt = most_frequent(nums)
        left, right = (0, cnt)
        for i in range(n):
            if nums[i] == dom:
                left += 1
                right -= 1
            if left * 2 > i + 1 and right * 2 > n - (i + 1):
                return i
        return -1
