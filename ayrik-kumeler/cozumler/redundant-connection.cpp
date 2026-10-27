class UnionFind {
    public:

    int* parent;
    int* rank;

    UnionFind(int n){
        rank = new int[n];
        parent = new int[n];

        for(int i=0; i<n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int Find(int node){

        if(parent[node] == node){
            return node;
        }
        return parent[node] = Find(parent[node]);
    }

    void Union(int u, int v){

        u = Find(u);
        v = Find(v);

        if(u != v){
            if(rank[u]<rank[v]){
                swap(u,v);
            }

            parent[v] = u;

            if(rank[u]==rank[v]){
                rank[u]++;
            }
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind UF = UnionFind(1001);

        for(vector<int>& edge : edges){
            int u = edge[0];
            int v = edge[1];

            if(UF.Find(u) == UF.Find(v)){
                return {u,v};
            }

            UF.Union(u,v);
        }

        return {-1};
    }
};
