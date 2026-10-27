class Solution:

    def numSimilarGroups(self, strs: List[str]) -> int:
        visited = set()
        count = 0
        for i in range(len(strs)):
            if i not in visited:
                self.dfs(strs, i, visited)
                count += 1
        return count

    def dfs(self, strs, i, visited):
        visited.add(i)
        for j in range(len(strs)):
            if self.isSimilar(strs[i], strs[j]) and j not in visited:
                self.dfs(strs, j, visited)

    def isSimilar(self, str1, str2):
        diff_count = 0
        for i in range(len(str1)):
            if str1[i] != str2[i]:
                diff_count += 1
        return diff_count <= 2
