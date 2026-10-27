class Solution(object):

    def findRepeatedDnaSequences(self, s):
        seqs = {}
        i = 0
        while i + 10 <= len(s):
            curr = s[i:i + 10]
            if curr in seqs:
                seqs[curr] = seqs[curr] + 1
            else:
                seqs[curr] = 1
            i += 1
        repeats = []
        for seq in list(seqs.keys()):
            if seqs[seq] > 1:
                repeats.append(seq)
        return repeats
