class Solution:

    def numDifferentIntegers(self, word: str) -> int:
        word = re.findall('(\\d+)', word)
        nums = [int(i) for i in word]
        return len(set(nums))
