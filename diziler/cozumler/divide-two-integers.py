class Solution:

    def divide(self, dividend: int, divisor: int) -> int:
        positive = (dividend < 0) == (divisor < 0)
        dividend, divisor = (abs(dividend), abs(divisor))
        if divisor == 1:
            quotient = dividend
        else:
            quotient = 0
            _sum = divisor
            while _sum <= dividend:
                current_quotient = 1
                while _sum + _sum <= dividend:
                    _sum += _sum
                    current_quotient += current_quotient
                dividend -= _sum
                _sum = divisor
                quotient += current_quotient
        if not positive:
            return max(-2147483648, -quotient)
        else:
            return min(quotient, 2147483647)
