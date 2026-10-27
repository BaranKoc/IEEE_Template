class Solution:

    def maximumBeauty(self, flowers: List[int], newFlowers: int, target: int, full: int, partial: int) -> int:
        already_complete = 0
        temp = []
        for f in flowers:
            if f >= target:
                already_complete += 1
            else:
                temp.append(f)
        max_beauty = 0
        flowers = temp
        flowers.sort()
        presum = [0] + list(accumulate(flowers))
        N = len(flowers)
        dp_arr = []
        for i in range(N + 1):
            if i < N:
                dp_arr.append((i + 1) * flowers[i] - presum[i + 1])
            right_sum = presum[-1] - presum[i]
            right_count = N - i
            if right_sum + newFlowers < right_count * target:
                continue
            rem_flowers = newFlowers - (right_count * target - right_sum)
            if i == 0:
                min_partial = 0
            else:
                j = min(bisect.bisect_right(dp_arr, rem_flowers) - 1, i - 1)
                min_partial = min((rem_flowers + presum[j + 1]) // (j + 1), target - 1)
            complete = right_count + already_complete
            max_beauty = max(max_beauty, complete * full + min_partial * partial)
        return max_beauty
