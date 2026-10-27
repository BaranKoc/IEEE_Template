from functools import cache

class Solution:

    def numberWays(self, hats: List[List[int]]) -> int:
        n_persons = len(hats)
        temp = [[] for _ in range(40)]
        for i, person in enumerate(hats):
            for hat in person:
                temp[hat - 1].append(i)
        hats = temp
        hats = [h for h in hats if h]
        hats.sort(key=lambda h: len(h))
        n_hats = len(hats)
        full = 2 ** n_persons - 1
        bits = [1 << i for i in range(n_persons)]
        cut = 10 ** 9 + 7

        @cache
        def get_count(i, has_hat):
            if has_hat == full:
                return 1
            elif i == n_hats:
                return 0
            else:
                result = 0
                for person in hats[i]:
                    if has_hat & bits[person] == 0:
                        result += get_count(i + 1, has_hat | bits[person])
                result += get_count(i + 1, has_hat)
                return result % cut
        return get_count(0, 0)
