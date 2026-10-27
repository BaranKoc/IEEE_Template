class PeekingIterator:

    def __init__(self, iterator):
        self.iterator = iterator
        self.buffer = self.iterator.next() if self.iterator.hasNext() else None

    def peek(self):
        return self.buffer

    def next(self):
        tmp = self.buffer
        self.buffer = self.iterator.next() if self.iterator.hasNext() else None
        return tmp

    def hasNext(self):
        return self.buffer != None
