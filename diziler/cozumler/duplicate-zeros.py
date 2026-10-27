class Solution:

    def duplicateZeros(self, arr: List[int]) -> None:
        l = len(arr)
        i, c = (0, 0)
        while i < l:
            if arr[i] == 0:
                arr.insert(i + 1, 0)
                i += 1
                arr.pop()
            i += 1
