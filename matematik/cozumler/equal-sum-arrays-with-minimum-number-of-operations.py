class Solution:

    def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
        sum1 = sum(nums1)
        sum2 = sum(nums2)
        if sum1 == sum2:
            return 0
        elif sum1 > sum2:
            larger_sum_nums = nums1
            smaller_sum_nums = nums2
        else:
            larger_sum_nums = nums2
            smaller_sum_nums = nums1
        sum_diff = abs(sum1 - sum2)
        gains_in_larger_array = [num - 1 for num in larger_sum_nums]
        gains_in_smaller_array = [6 - num for num in smaller_sum_nums]
        gains = gains_in_larger_array + gains_in_smaller_array
        gains.sort(reverse=True)
        count = 0
        target_diff = sum_diff
        for i in range(len(gains)):
            target_diff -= gains[i]
            count += 1
            if target_diff <= 0:
                return count
        return -1
