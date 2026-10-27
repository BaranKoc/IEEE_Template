class Solution:

    def countRestrictedPaths(self, n: int, edges: List[List[int]]) -> int:
        dct_nd = {}
        dist_to_n = {}
        queue = deque()
        visited = set()
        for l, r, w in edges:
            dct_nd[l] = dct_nd.get(l, []) + [(w, r)]
            dct_nd[r] = dct_nd.get(r, []) + [(w, l)]
        dist_to_n[n] = 0
        queue.append(n)
        visited.add(n)
        hpf = dct_nd[n].copy()
        heapify(hpf)
        while hpf:
            el_w, el_nd = heappop(hpf)
            if el_nd in visited:
                continue
            dist_to_n[el_nd] = el_w
            visited.add(el_nd)
            queue.append(el_nd)
            if el_nd == 1:
                break
            for i_w, i_nd in dct_nd[el_nd]:
                if i_nd not in visited:
                    heappush(hpf, (el_w + i_w, i_nd))
        dist_to_n = {k: [v, 0] for k, v in dist_to_n.items()}
        dist_to_n[n] = [dist_to_n[n][0], 1]
        visited.clear()
        while queue:
            nd_prv = queue.popleft()
            visited.add(nd_prv)
            for w_cur, nd_cur in dct_nd[nd_prv]:
                if nd_cur not in visited and nd_cur in dist_to_n.keys() and (dist_to_n[nd_cur][0] > dist_to_n[nd_prv][0]):
                    dist_to_n[nd_cur][1] += dist_to_n[nd_prv][1]
                    dist_to_n[nd_cur][1] = int(dist_to_n[nd_cur][1] % (1000000000.0 + 7))
        return dist_to_n[1][1]
