class Solution(object):

    def __init__(self, w):
        self.list = [0] * len(w)
        s = 0
        for i, n in enumerate(w):
            s += n
            self.list[i] = s

    def pickIndex(self):
        return bisect_left(self.list, random.randint(1, self.list[-1]))
