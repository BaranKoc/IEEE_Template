class Scout:

    def __init__(self, prev_idx=-1, count_of_equal=0):
        self.prev_idx = prev_idx
        self.count_of_equal = count_of_equal

    def __iter__(self):
        return iter((self.prev_idx, self.count_of_equal))

class Solution:

    def getDistances(self, arr: List[int]) -> List[int]:
        size = len(arr)
        pre_scout = defaultdict(Scout)
        pre_dist_sum = [0 for _ in range(size)]
        post_scout = defaultdict(Scout)
        post_dist_sum = [0 for _ in range(size)]
        for i, element in enumerate(arr):
            prev_equal_idx, prev_count_of_equal = pre_scout[element]
            if prev_count_of_equal:
                pre_dist_sum[i] += pre_dist_sum[prev_equal_idx] + (i - prev_equal_idx) * prev_count_of_equal
            pre_scout[element] = (i, prev_count_of_equal + 1)
        for i, element in reversed([*enumerate(arr)]):
            post_equal_idx, post_count_of_equal = post_scout[element]
            if post_count_of_equal:
                post_dist_sum[i] += post_dist_sum[post_equal_idx] + (post_equal_idx - i) * post_count_of_equal
            post_scout[element] = (i, post_count_of_equal + 1)
        return [pre_dist_sum[i] + post_dist_sum[i] for i in range(size)]
