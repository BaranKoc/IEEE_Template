class Solution:

    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        for i in range(len(box)):
            stone = 0
            for j in range(len(box[0])):
                if box[i][j] == '#':
                    stone += 1
                    box[i][j] = '.'
                elif box[i][j] == '*':
                    for m in range(stone):
                        box[i][j - m - 1] = '#'
                    stone = 0
            if stone != 0:
                for m in range(stone):
                    box[i][j - m] = '#'
        box[:] = zip(*box[::-1])
        return box
