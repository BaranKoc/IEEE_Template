class Solution(object):

    def countCharacters(self, words, chars):
        b = set(chars)
        anwser = 0
        for i in words:
            a = set(i)
            if a.issubset(b):
                test = [o for o in a if chars.count(o) < i.count(o)]
                if len(test) == 0:
                    anwser += len(i)
        return anwser
