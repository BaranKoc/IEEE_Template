def cal(ele):
    return ele[0] ** 2 + ele[1] ** 2

def partition(arr, start, end):
    rdIdx = randint(start, end)
    arr[rdIdx], arr[end] = (arr[end], arr[rdIdx])
    pivot = arr[end]
    i = start - 1
    pivot_dis = cal(pivot)
    for j in range(start, end):
        if cal(arr[j]) <= pivot_dis:
            i += 1
            arr[j], arr[i] = (arr[i], arr[j])
    arr[i + 1], arr[end] = (arr[end], arr[i + 1])
    return i + 1

def qSelect(arr, kth, start, end):
    if start < end:
        pv = partition(arr, start, end)
        if pv == kth:
            return
        if kth < pv:
            return qSelect(arr, kth, start, pv - 1)
        else:
            return qSelect(arr, kth, pv + 1, end)

class Solution:

    def kClosest(self, points, k):
        qSelect(points, k - 1, 0, len(points) - 1)
        return points[:k]
