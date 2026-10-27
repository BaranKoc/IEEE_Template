class Solution(object):

    def squareFreeSubsets(self, nums):
        freqs = {}
        for val in nums:
            freqs[val] = freqs.get(val, 0) + 1
        factors = {6: [2, 3], 10: [2, 5], 14: [2, 7], 15: [3, 5], 21: [3, 7], 22: [2, 11], 26: [2, 13], 30: [2, 3, 5]}
        primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
        invalid = [4, 8, 9, 12, 16, 18, 20, 24, 25, 27, 28]
        compressed = set(nums)
        reduced = sorted([val for val in compressed if val not in invalid])
        if not reduced:
            return 0
        self.total = 0
        if reduced[0] == 1:
            reduced.pop(0)

        def traverse(index, used, subtotal):
            if index == len(reduced):
                self.total += subtotal
                self.total %= 1000000007
                return
            valid = True
            number = reduced[index]
            if number in factors.keys():
                for factor in factors[number]:
                    if factor in used:
                        valid = False
                        break
            elif number in used:
                valid = False
            traverse(index + 1, used[:], subtotal)
            if valid:
                if number in factors.keys():
                    for factor in factors[number]:
                        used.append(factor)
                else:
                    used.append(number)
                subtotal *= freqs[number]
                subtotal %= 1000000007
                traverse(index + 1, used[:], subtotal)
        traverse(0, [], 1)
        if 1 in freqs.keys():
            return ((self.total - 1) * pow(2, freqs[1]) + (pow(2, freqs[1]) - 1)) % 1000000007
        return (self.total - 1) % 1000000007
