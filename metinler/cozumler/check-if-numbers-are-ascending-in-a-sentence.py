class Solution:

    def areNumbersAscending(self, s):
        nums = re.findall('\\d+', s)
        return nums == sorted(set(nums), key=int)
