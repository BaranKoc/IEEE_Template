class Solution:

    def addSpaces(self, s: str, spaces: List[int]) -> str:
        arr = []
        prev = 0
        for space in spaces:
            arr.append(s[prev:space])
            prev = space
        arr.append(s[space:])
        return ' '.join(arr)
