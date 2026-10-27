from collections import Counter

class Solution:

    def buddyStrings(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False
        diffCharactersCount = 0
        diffCharactersInS = []
        diffCharactersInGoal = []
        for i in range(len(s)):
            if s[i] != goal[i]:
                diffCharactersCount += 1
                diffCharactersInS.append(s[i])
                diffCharactersInGoal.append(goal[i])
        if diffCharactersCount == 2:
            if diffCharactersInS[0] == diffCharactersInGoal[1] and diffCharactersInS[1] == diffCharactersInGoal[0]:
                return True
            return False
        elif diffCharactersCount == 0:
            counts = Counter(s)
            for k, v in counts.items():
                if v > 1:
                    return True
        return False
