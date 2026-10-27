class Solution:

    def abbreviateProduct(self, left: int, right: int) -> str:
        c2 = c5 = 0
        top12 = tail5 = 1
        for i in range(left, right + 1):
            while i % 2 == 0:
                i //= 2
                c2 += 1
            while i % 5 == 0:
                i //= 5
                c5 += 1
            top12 = int(str(top12 * i)[:12])
            tail5 = tail5 * i % 100000
        if c2 > c5:
            for _ in range(c2 - c5):
                top12 = int(str(top12 * 2)[:12])
                tail5 = tail5 * 2 % 100000
        elif c2 < c5:
            for _ in range(c5 - c2):
                top12 = int(str(top12 * 5)[:12])
                tail5 = tail5 * 5 % 100000
        zero = min(c2, c5)
        if len(str(top12)) <= 10:
            return str(top12) + 'e' + str(zero)
        return str(top12)[:5] + '.' * 3 + '0' * (5 - len(str(tail5))) + str(tail5) + 'e' + str(zero)
