class Solution:

    def earliestAndLatest(self, n: int, first: int, second: int) -> List[int]:

        def ceiling_of_log2(x: int) -> int:
            assert 0 < x < 4294967296
            offset = 1 if x & x - 1 != 0 else 0
            x |= x >> 1
            x |= x >> 2
            x |= x >> 4
            x |= x >> 8
            x |= x >> 16
            return popcount(x) - 1 + offset

        def popcount(x: int) -> int:
            assert 0 <= x < 4294967296
            x = x - (x >> 1 & 1431655765)
            x = (x & 858993459) + (x >> 2 & 858993459)
            return ((x + (x >> 4) & 252645135) * 16843009 & 4294967295) >> 24

        def count_trailing_zeroes(x: int) -> int:
            assert 0 < x < 4294967296
            if x & 1:
                return 0
            c = 1
            if x & 65535 == 0:
                x >>= 16
                c += 16
            if x & 255 == 0:
                x >>= 8
                c += 8
            if x & 15 == 0:
                x >>= 4
                c += 4
            if x & 3 == 0:
                x >>= 2
                c += 2
            return c - (x & 1)
        if first + second == n + 1:
            return [1, 1]
        if first + second >= n + 1:
            first, second = (n + 1 - second, n + 1 - first)
        first_plus_second = first + second
        if first + 1 != second and first_plus_second >= (n + 1) // 2 + 1:
            if first_plus_second == n:
                if n % 4 == 2 and first + 2 == second:
                    ans_earliest = 3 + count_trailing_zeroes(n // 4)
                else:
                    ans_earliest = 3 - first % 2
            else:
                ans_earliest = 2
        else:
            ans_earliest = 1 + ceiling_of_log2((n + first_plus_second - 2) // (first_plus_second - 1))
            if first + 1 == second:
                ans_earliest += count_trailing_zeroes((n + (1 << ans_earliest - 1) - 1 >> ans_earliest - 1) - 1)
        ans_latest = min(ceiling_of_log2(n), n + 1 - second)
        return [ans_earliest, ans_latest]
