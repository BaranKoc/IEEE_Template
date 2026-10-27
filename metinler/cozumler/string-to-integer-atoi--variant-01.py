class Solution:

    def assign_sign(self, sign):
        if not self.is_neg and (not self.is_pos):
            if sign == '+':
                self.is_pos = True
            elif sign == '-':
                self.is_neg = True
        return

    def add_to_int(self, num):
        if not self.num:
            self.num = num
        else:
            self.num = self.num * 10 + num

    def myAtoi(self, s: str) -> int:
        self.is_neg = False
        self.is_pos = False
        self.num = None
        s = s.strip()
        for i in s:
            if i in ('+', '-'):
                if self.is_pos or self.is_neg or isinstance(self.num, int):
                    break
                self.assign_sign(i)
                continue
            try:
                i = int(i)
                self.add_to_int(i)
            except ValueError:
                break
        if not self.num:
            return 0
        upper_limit = 2 ** 31 - 1
        if self.is_pos or (not self.is_pos and (not self.is_neg)):
            if self.num > upper_limit:
                self.num = upper_limit
        elif self.is_neg:
            if self.num > upper_limit + 1:
                self.num = upper_limit + 1
            self.num = -1 * self.num
        return self.num
