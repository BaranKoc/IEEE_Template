class Solution:

    def arrangeWords(self, text: str) -> str:
        a = []
        for x in text.split(' '):
            a.append(x.lower())
        return ' '.join(sorted(a, key=len)).capitalize()
