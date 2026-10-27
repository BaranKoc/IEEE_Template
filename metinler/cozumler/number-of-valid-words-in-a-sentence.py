import re

class Solution:

    def countValidWords(self, sentence: str) -> int:
        words = sentence.split()
        pattern = re.compile('^([a-z]+\\-?[a-z]+[!\\.,]?)$|^([a-z]*[!\\.,]?)$')
        count = 0
        for word in words:
            match = re.match(pattern, word)
            if match:
                count += 1
        return count
