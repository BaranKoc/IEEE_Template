class Solution:

    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        return [(s + k * fill)[i:i + k] for i in range(0, len(s), k)]
