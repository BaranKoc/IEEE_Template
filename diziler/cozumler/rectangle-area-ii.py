class SegmentTree:

    def __init__(self, xs):
        self.cnts = defaultdict(int)
        self.total = defaultdict(int)
        self.xs = xs

    def update(self, v, tl, tr, l, r, h):
        if r < tl or tr < l:
            return
        if l <= tl and tr <= r:
            self.cnts[v] += h
        else:
            tm = (tl + tr) // 2
            self.update(v * 2, tl, tm, l, r, h)
            self.update(v * 2 + 1, tm + 1, tr, l, r, h)
        if self.cnts[v] > 0:
            self.total[v] = self.xs[tr + 1] - self.xs[tl]
        else:
            self.total[v] = self.total[v * 2] + self.total[v * 2 + 1]
        return self.total[v]

class Solution:

    def rectangleArea(self, rectangles):
        xs = sorted(set([x for x1, y1, x2, y2 in rectangles for x in [x1, x2]]))
        xs_i = {x: i for i, x in enumerate(xs)}
        st = SegmentTree(xs)
        L = []
        for x1, y1, x2, y2 in rectangles:
            L.append([y1, 1, x1, x2])
            L.append([y2, -1, x1, x2])
        L.sort()
        cur_y = cur_x_sum = area = 0
        for y, open_close, x1, x2 in L:
            area += (y - cur_y) * cur_x_sum
            cur_y = y
            st.update(1, 0, len(xs) - 1, xs_i[x1], xs_i[x2] - 1, open_close)
            cur_x_sum = st.total[1]
        return area % (10 ** 9 + 7)
