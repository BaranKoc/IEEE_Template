class Solution:

    def _get_char_counts(self, s: str) -> dict[str]:
        d = {}
        for i in s:
            d[i] = d.get(i, 0) + 1
        return d

    def commonChars(self, words: list[str]) -> list[str]:
        if not words:
            return
        words = [self._get_char_counts(word) for word in words]
        common = words[0].keys()
        for other in words[1:]:
            common &= other.keys()
        result = []
        for c in common:
            result += [c] * min((count[c] for count in words))
        return result
