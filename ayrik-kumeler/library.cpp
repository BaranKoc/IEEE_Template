#include <algorithm>
#include <cstdint>
#include <functional>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

namespace ieee_template {

namespace disjoint_set {
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
}

}
