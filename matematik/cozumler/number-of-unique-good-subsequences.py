class Solution:

    def numberOfUniqueGoodSubsequences(self, binary: str) -> int:
        dp = {'zero_as_last': 0, 'one_as_last': 0, 'zero_exist': 0}
        for bit in map(int, binary):
            if bit:
                dp['one_as_last'] = dp['zero_as_last'] + dp['one_as_last'] + 1
            else:
                dp['zero_as_last'] = dp['zero_as_last'] + dp['one_as_last']
            dp['zero_exist'] |= 1 - bit
        return sum(dp.values()) % (10 ** 9 + 7)
