class Solution:

    def rankTeams(self, votes: List[str]) -> str:
        d = {}
        for vote in votes:
            for i, c in enumerate(vote):
                if c not in d:
                    d[c] = [0] * len(vote)
                d[c][i] += 1
        vote_names = sorted(d.keys())
        vote_rank = sorted(vote_names, reverse=True, key=lambda x: d[x])
        return ''.join(vote_rank)
