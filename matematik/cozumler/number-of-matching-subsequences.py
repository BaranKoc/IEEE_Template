class Solution:

    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        word_dict = defaultdict(list)
        numMatch = 0
        for w in words:
            word_dict[ord(w[0]) - ord('a')].append(w)
        for c in s:
            qualified = word_dict[ord(c) - ord('a')]
            word_dict[ord(c) - ord('a')] = []
            for q in qualified:
                if len(q) == 1:
                    numMatch += 1
                else:
                    word_dict[ord(q[1]) - ord('a')].append(q[1:])
        return numMatch
