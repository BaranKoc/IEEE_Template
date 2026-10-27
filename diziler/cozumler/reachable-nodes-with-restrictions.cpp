class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {

        vector<int> adj[n];

        vector<int> vis(n,0);

        int cnt = 0;

        for(int i=0;i<restricted.size();i++)
            vis[restricted[i]] = 1;

        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        dfs(adj, vis, 0, cnt);

        return cnt;

    }

    void dfs(vector<int> adj[], vector<int> &vis, int node, int &cnt)
    {
        vis[node] = 1;
        cnt++;

        for(auto it : adj[node])
        {
            if(!vis[it])
                dfs(adj, vis, it, cnt);
        }
    }

};
