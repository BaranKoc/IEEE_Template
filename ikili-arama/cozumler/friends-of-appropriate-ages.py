class Solution:

    def binary_search(self, arr, low, high, value):
        if low > high:
            return high
        mid = (low + high) // 2
        if arr[mid] > value:
            return self.binary_search(arr, low, mid - 1, value)
        else:
            return self.binary_search(arr, mid + 1, high, value)

    def numFriendRequests(self, ages: List[int]) -> int:
        ages = sorted(ages)
        total_count = 0
        for i in range(len(ages) - 1, -1, -1):
            if i + 1 < len(ages) and ages[i] == ages[i + 1]:
                total_count += prev_count
                continue
            prev_count = 0
            lower_limit = 0.5 * ages[i] + 7
            index = self.binary_search(ages, 0, i - 1, lower_limit)
            prev_count = i - (index + 1)
            total_count += prev_count
        return total_count
