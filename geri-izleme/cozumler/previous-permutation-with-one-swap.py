class Solution:

    def find_max(self, i, a, n):
        maxs = i + 1
        for j in range(n - 1, i, -1):
            if a[maxs] <= a[j] and a[j] < a[i]:
                maxs = j
        a[i], a[maxs] = (a[maxs], a[i])
        return a

    def prevPermOpt1(self, arr):
        n = len(arr)
        for i in range(n - 1, 0, -1):
            if arr[i] < arr[i - 1]:
                arr = self.find_max(i - 1, arr, n)
                break
        return arr
