class Solution:

    def kMirror(self, k: int, n: int) -> int:

        def numberToBase(n, b):
            if n == 0:
                return [0]
            digits = []
            while n:
                digits.append(n % b)
                n //= b
            return digits[::-1]

        def baseToNumber(arr, b):
            ans = 0
            for x in arr:
                ans = ans * b + int(x)
            return ans

        def is_mirror(s):
            l, r = (0, len(s) - 1)
            while l <= r:
                if s[l] != s[r]:
                    return False
                l += 1
                r -= 1
            return True

        def gen():
            for i in range(30):
                for num in range(10 ** i, 10 ** (i + 1)):
                    s = str(num) + str(num)[::-1][1:]
                    yield int(s)
                for num in range(10 ** i, 10 ** (i + 1)):
                    s = str(num) + str(num)[::-1]
                    yield int(s)
        ans = 0
        left = n
        for num in gen():
            base = numberToBase(num, k)
            if base == base[::-1]:
                ans += num
                left -= 1
            if left == 0:
                break
        return ans
