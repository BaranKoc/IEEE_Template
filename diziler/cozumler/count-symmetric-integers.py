class Solution(object):

    def countSymmetricIntegers(self, low, high):
        all = 0
        for i in range(low, high + 1):
            i = str(i)
            if len(i) % 2 == 0:
                if sum([int(i[x]) for x in range(0, len(i) / 2)]) == sum([int(i[x]) for x in range(len(i) / 2, len(i))]):
                    all += 1
        return all
