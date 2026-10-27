class Solution:

    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        ans = set(arr)
        one = set()
        one.add(arr[0])
        for i in range(1, len(arr)):
            two = set()
            for j in one:
                two.add(j | arr[i])
                ans.add(j | arr[i])
            two.add(arr[i])
            one = two
        return len(ans)
