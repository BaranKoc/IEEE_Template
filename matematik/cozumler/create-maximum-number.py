class Solution:

    def maxNumber(self, nums1: List[int], nums2: List[int], k: int) -> List[int]:
        m = len(nums1)
        n = len(nums2)
        dp = {}

        def getMaxNumberString(i, j, length):
            if length == 0:
                return ''
            key = (i, j, length)
            if key in dp:
                return dp[key]
            index1 = None
            for ii in range(i, m):
                if m - ii + n - j < length:
                    break
                if index1 is None or nums1[index1] < nums1[ii]:
                    index1 = ii
            index2 = None
            for jj in range(j, n):
                if m - i + n - jj < length:
                    break
                if index2 is None or nums2[index2] < nums2[jj]:
                    index2 = jj
            maxNumberStr = None
            if index1 is not None and index2 is not None:
                if nums1[index1] > nums2[index2]:
                    maxNumberStr = str(nums1[index1]) + getMaxNumberString(index1 + 1, j, length - 1)
                elif nums1[index1] < nums2[index2]:
                    maxNumberStr = str(nums2[index2]) + getMaxNumberString(i, index2 + 1, length - 1)
                else:
                    maxNumberStr = max(str(nums1[index1]) + getMaxNumberString(index1 + 1, j, length - 1), str(nums2[index2]) + getMaxNumberString(i, index2 + 1, length - 1))
            elif index1 is not None:
                maxNumberStr = str(nums1[index1]) + getMaxNumberString(index1 + 1, j, length - 1)
            elif index2 is not None:
                maxNumberStr = str(nums2[index2]) + getMaxNumberString(i, index2 + 1, length - 1)
            dp[key] = maxNumberStr
            return maxNumberStr
        result_str = getMaxNumberString(0, 0, k)
        result = []
        for c in result_str:
            result.append(int(c))
        return result
