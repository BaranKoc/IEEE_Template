class Solution:

    def fullBloomFlowers(self, flowers: List[List[int]], people: List[int]) -> List[int]:
        starts = sorted(flowers)
        blooming = []
        answer = [-1] * len(people)
        hours = [(people[i], i) for i in range(len(people))]
        hours.sort()
        i = 0
        for hour, person in hours:
            while i < len(starts) and starts[i][0] <= hour:
                heappush(blooming, (starts[i][1], starts[i][0]))
                i += 1
            while blooming and blooming[0][0] < hour:
                heappop(blooming)
            answer[person] = len(blooming)
        return answer
