class Solution(object):

    def hIndex(self, citations):
        left, right, mid = (0, len(citations) - 1, 0)
        while left < right:
            mid = (left + right) // 2
            if len(citations) - mid <= citations[mid]:
                right = mid
            else:
                left = mid + 1
        if citations[left] == 0:
            return 0
        return len(citations) - left
