class Solution:

    def maximumBobPoints(self, numArrows: int, aliceArrows: List[int]) -> List[int]:
        max_score = [0, None]

        def calc(i, remaining, score, arrows):
            if remaining == 0 or i == -1:
                if score > max_score[0]:
                    max_score[0] = score
                    max_score[1] = arrows[:]
                return
            if i == 0:
                arrows[i] = remaining
                calc(i - 1, 0, score + i, arrows)
                arrows[i] = 0
                return
            arrowsNeeded = aliceArrows[i] + 1
            if remaining >= arrowsNeeded:
                arrows[i] = arrowsNeeded
                calc(i - 1, remaining - arrowsNeeded, score + i, arrows)
                arrows[i] = 0
            calc(i - 1, remaining, score, arrows)
        calc(len(aliceArrows) - 1, numArrows, 0, [0 for _ in aliceArrows])
        return max_score[1]
