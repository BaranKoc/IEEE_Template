class Solution {
private:
    int n = 0;

    vector<int> subtree_distance;

    vector<int> subtree_count;
public:
    void postorder(int root, int parent, vector<vector<int>>& graph) {

        for(auto child: graph[root]) {

            if(child != parent) {
                postorder(child, root, graph);

                subtree_count[root] += subtree_count[child];

                subtree_distance[root] += subtree_distance[child] + subtree_count[child];
            }
        }
    }

    void preorder(int root, int parent, vector<vector<int>>& graph) {
        for(auto child: graph[root]) {
            if(child != parent) {

                subtree_distance[child] = subtree_distance[root] - subtree_count[child] + (n - subtree_count[child]);
                preorder(child, root, graph);
            }
        }
    }

    vector<int> reRootingSol(int n, vector<vector<int>>& edges) {

        vector<vector<int> > graph(n);
        for(auto edge: edges) {
            int src = edge[0], dst = edge[1];
            graph[src].emplace_back(dst);
            graph[dst].emplace_back(src);
        }

        this->n = n;
        this->subtree_count.resize(n, 1);
        this->subtree_distance.resize(n, 0);

        postorder(0, -1, graph);

        preorder(0, -1, graph);
        return this->subtree_distance;
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        return reRootingSol(n, edges);
    }
};
