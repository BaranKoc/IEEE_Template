class Solution:

    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        if len(s) <= numRows:
            return s
        if numRows == 2:
            return s[0::2] + s[1::2]
        lines: list[str] = [letter for letter in s[:numRows]]
        direction: int = -1
        line_index: int = numRows - 2
        edges: set[int] = {0, numRows}
        for letter in s[numRows:]:
            lines[line_index] += letter
            line_index += direction
            if line_index in edges:
                direction = -direction
                if line_index == numRows:
                    line_index += direction * 2
        return ''.join(lines)
