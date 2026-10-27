class Solution:

    def largestTimeFromDigits(self, arr: List[int]) -> str:
        res = ''
        digit_freq = collections.Counter(arr)
        if 2 in arr and sum([digit_freq[d] for d in range(6)]) > 2:
            res += '2'
            arr.remove(2)
        else:
            for digit in [1, 0]:
                if digit in arr:
                    res += str(digit)
                    arr.remove(digit)
                    break
        if len(res) == 0:
            return ''
        if res == '2':
            for digit in [3, 2, 1, 0]:
                if digit in arr:
                    res += str(digit)
                    arr.remove(digit)
                    break
            if len(res) == 1:
                return ''
        else:
            for digit in range(9, -1, -1):
                if digit in arr:
                    res += str(digit)
                    arr.remove(digit)
                    break
        res += ':'
        for digit in range(5, -1, -1):
            if digit in arr:
                res += str(digit)
                arr.remove(digit)
                break
        if len(res) == 3:
            return ''
        for digit in range(9, -1, -1):
            if digit in arr:
                res += str(digit)
                return res
