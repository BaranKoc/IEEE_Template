class Solution:

    def wordCount(self, startWords: List[str], targetWords: List[str]) -> int:
        cnt = 0
        for target in targetWords:
            for start in startWords:
                if len(target) - len(start) == 1 and len(set(list(target)) - set(list(start))) == 1:
                    cnt += 1
                    break
        return cnt

class Solution:

    def wordCount(self, startWords: List[str], targetWords: List[str]) -> int:
        startWords_sorted = set()
        for word in startWords:
            startWords_sorted.add(''.join(sorted(list(word))))
        targetWords_sorted = []
        for word in targetWords:
            targetWords_sorted.append(sorted(list(word)))
        cnt = 0
        for target in targetWords_sorted:
            for i in range(len(target)):
                w = target[:i] + target[i + 1:]
                w = ''.join(w)
                if w in startWords_sorted:
                    cnt += 1
                    break
        return cnt

class Solution:

    def wordCount(self, startWords: List[str], targetWords: List[str]) -> int:
        start_set = set()
        for word in startWords:
            m = 0
            for ch in word:
                i = ord(ch) - ord('a')
                m |= 1 << i
            start_set.add(m)
        cnt = 0
        for word in targetWords:
            m = 0
            for ch in word:
                i = ord(ch) - ord('a')
                m |= 1 << i
            for ch in word:
                i = ord(ch) - ord('a')
                if m ^ 1 << i in start_set:
                    cnt += 1
                    break
        return cnt
