class CountIntervals:

    def __init__(self):
        self.interv = [(-inf, -inf), (inf, inf)]
        self.cov = 0

    def add(self, left: int, right: int) -> None:
        interv = self.interv
        li = bisect.bisect_left(interv, left - 1, key=itemgetter(1))
        lval = min(interv[li][0], left)
        ri = bisect.bisect_right(interv, right + 1, key=itemgetter(0))
        rval = max(interv[ri - 1][1], right)
        to_delete = 0
        for _ in range(li, ri):
            to_delete += interv[_][1] - interv[_][0] + 1
        self.cov += rval - lval + 1 - to_delete
        interv[li:ri] = [(lval, rval)]

    def count(self) -> int:
        return self.cov
