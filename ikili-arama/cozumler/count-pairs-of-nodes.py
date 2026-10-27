class Solution:

    def countPairs(self, n: int, edges: List[List[int]], queries: List[int]) -> List[int]:
        p_c = [0] * (n + 1)
        e_c = defaultdict(int)
        for a, b in edges:
            p_c[a] += 1
            p_c[b] += 1
            if a < b:
                e_c[a, b] += 1
            else:
                e_c[b, a] += 1
        f_c = defaultdict(int)
        for i in range(1, n + 1):
            f_c[p_c[i]] += 1
        cnt_amt = defaultdict(int)
        f_key = list(f_c.keys())
        l_f = len(f_key)
        for i in range(l_f):
            f1 = f_key[i]
            cnt_amt[f1 * 2] += f_c[f1] * (f_c[f1] - 1) // 2
            for j in range(i + 1, l_f):
                f2 = f_key[j]
                cnt_amt[f1 + f2] += f_c[f1] * f_c[f2]
        for (u, v), z in e_c.items():
            s = p_c[u] + p_c[v]
            t = s - z
            cnt_amt[s] -= 1
            cnt_amt[t] += 1
        cnt_keys = sorted(cnt_amt.keys(), key=lambda x: -x)
        res = defaultdict(int)
        tmp = 0
        for key in cnt_keys:
            if cnt_amt[key]:
                tmp += cnt_amt[key]
                res[key] = tmp
        res_keys = sorted(res.keys())
        for i, q in enumerate(queries):
            local = bisect.bisect(res_keys, q)
            try:
                queries[i] = res[res_keys[local]]
            except:
                queries[i] = 0
        return queries
