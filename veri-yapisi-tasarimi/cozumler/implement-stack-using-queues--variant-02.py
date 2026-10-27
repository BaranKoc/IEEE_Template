class MyStack(object):

    def __init__(self):
        self.stack = []

    def push(self, x):
        self.stack.append(x)
        return None

    def pop(self):
        return self.stack.pop(-1)

    def top(self):
        return self.stack[-1]

    def empty(self):
        if self.stack == []:
            return True
        return False
