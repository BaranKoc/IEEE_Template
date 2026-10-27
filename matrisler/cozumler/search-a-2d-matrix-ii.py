class Solution(object):

    def searchMatrix(self, matrix, target):
        found = False
        for X in matrix:
            for M in X:
                if M == target:
                    found = True
        return found
