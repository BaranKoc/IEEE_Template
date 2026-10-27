class Solution:

    def minDeletionSize(self, strs: List[str]) -> int:
        n = len(strs)
        col_size = len(strs[0])
        i = 0
        ans = 0

        def getRemoved(idx):
            for x in range(n):
                strs[x] = strs[x][:idx] + strs[x][idx + 1:]
        while i < col_size:
            tmp = strs[0][:i + 1]
            flag = True
            similar = False
            for j in range(1, n):
                if strs[j][:i + 1] < tmp:
                    flag = False
                    break
                elif strs[j][:i + 1] > tmp:
                    tmp = strs[j][:i + 1]
                else:
                    tmp = strs[j][:i + 1]
                    similar = True
            if flag == True and similar == False:
                return ans
            elif flag == True and similar == True:
                i += 1
            elif flag == False:
                getRemoved(i)
                ans += 1
                col_size -= 1
        return ans
