class Solution:

    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        pattern = '(?<=\\b' + first + ' ' + second + ' )[a-z]*'
        txt = re.findall(pattern, text)
        return txt
