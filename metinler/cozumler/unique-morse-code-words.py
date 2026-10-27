class Solution:

    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        ENG_to_MORSE = {'a': '.-', 'b': '-...', 'c': '-.-.', 'd': '-..', 'e': '.', 'f': '..-.', 'g': '--.', 'h': '....', 'i': '..', 'j': '.---', 'k': '-.-', 'l': '.-..', 'm': '--', 'n': '-.', 'o': '---', 'p': '.--.', 'q': '--.-', 'r': '.-.', 's': '...', 't': '-', 'u': '..-', 'v': '...-', 'w': '.--', 'x': '-..-', 'y': '-.--', 'z': '--..'}
        cnt = {}
        for word in words:
            tmp = ''
            for c in word:
                tmp += ENG_to_MORSE[c]
            if tmp not in cnt:
                cnt[tmp] = 0
            else:
                cnt[tmp] += 1
        return len(cnt)
