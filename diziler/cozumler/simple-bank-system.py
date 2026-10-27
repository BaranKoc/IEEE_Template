class Bank:

    def __init__(self, bal: List[int]):
        self.store = bal

    def transfer(self, a1: int, a2: int, money: int) -> bool:
        try:
            if self.store[a1 - 1] >= money and self.store[a2 - 1] >= 0:
                self.store[a1 - 1] -= money
                self.store[a2 - 1] += money
                return True
            else:
                return False
        except:
            return False

    def deposit(self, ac: int, mn: int) -> bool:
        try:
            self.store[ac - 1] += mn
            return True
        except:
            return False

    def withdraw(self, ac: int, mn: int) -> bool:
        try:
            if self.store[ac - 1] >= mn:
                self.store[ac - 1] -= mn
                return True
            else:
                return False
        except:
            return False
