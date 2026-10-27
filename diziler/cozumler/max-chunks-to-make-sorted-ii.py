class Solution:

    def maxChunksToSorted(self, arr: List[int]) -> int:
        sortedArr = sorted(arr)
        posMap = defaultdict(list)
        for i in range(len(sortedArr)):
            posMap[sortedArr[i]].append(i)
        idx = len(arr) - 1
        cnt = 0
        for i in range(len(arr) - 1, -1, -1):
            idx = min(idx, posMap[arr[i]][-1])
            posMap[arr[i]].pop()
            if i == idx:
                cnt += 1
                idx -= 1
        return cnt
