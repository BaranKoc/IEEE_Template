class Solution:

    def isPerfectSquare(self, num: int) -> bool:
        if num == 1:
            return True
        lo = 2
        hi = num // 2
        while lo <= hi:
            mid = lo + (hi - lo) // 2
            print(mid)
            if mid * mid == num:
                return True
            if mid * mid > num:
                hi = mid - 1
            else:
                lo = mid + 1
        return False
