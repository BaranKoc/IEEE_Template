from bisect import bisect_left

class Solution:

    def avoidFlood(self, rains):
        full_lakes, dry_dates = ({}, [])
        ans = [-1] * len(rains)
        for date, rain_lake in enumerate(rains):
            if rain_lake == 0:
                dry_dates.append(date)
                continue
            if rain_lake in full_lakes:
                dry_day = bisect_left(dry_dates, full_lakes[rain_lake])
                if dry_day >= len(dry_dates):
                    return []
                ans[dry_dates.pop(dry_day)] = rain_lake
            full_lakes[rain_lake] = date
        for dry_day in dry_dates:
            ans[dry_day] = 1
        return ans
