class Solution:

    def maxArea(self, arr: List[List[int]]) -> int:
        maxA = 0
        stack = [-1]
        arr.append(-1)
        for i in range(len(arr)):
            arr[i] = int(arr[i])
            while stack and arr[stack[-1]] >= int(arr[i]):
                index = stack.pop()
                width = i - stack[-1] - 1 if stack else i
                maxA = max(maxA, width * arr[index])
            stack.append(int(i))
        return maxA

    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        result = [0] * len(matrix[0])
        maxReact = 0
        maxReact = self.maxArea(result)
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                matrix[i][j] = int(matrix[i][j])
                if matrix[i][j] == 0:
                    result[j] = 0
                else:
                    result[j] = result[j] + matrix[i][j]
            maxReact = max(maxReact, self.maxArea(result))
        return maxReact
