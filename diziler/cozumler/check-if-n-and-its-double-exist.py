class Solution(object):

    def checkIfExist(self, arr):
        arr = sorted(arr)
        for i in range(len(arr) - 1):
            l = 0
            r = len(arr) - 1
            while l <= r:
                mid = int((l + r) / 2)
                val1 = arr[mid]
                val2 = arr[i] * 2
                if val1 == val2 and mid != i:
                    return True
                elif val2 < val1:
                    r = mid - 1
                else:
                    l = mid + 1
        return False
