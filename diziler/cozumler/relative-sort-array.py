class Solution:

    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        dic = {}
        for elem in arr1:
            if dic.get(elem) is None:
                dic[elem] = 1
            else:
                dic[elem] = dic[elem] + 1
        output = []
        for elem in arr2:
            output += [elem] * dic[elem]
        extra_output = []
        for elem in set(arr1) - set(arr2):
            extra_output += [elem] * dic[elem]
        return output + sorted(extra_output)
