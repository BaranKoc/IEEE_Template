class Solution {
public:

    vector<int> topologicalSort(vector<unordered_set<int> >& graph, vector<int>& indegree) {
        vector<int> order;
        int processed = 0, n = graph.size();

        queue<int> q;

        for(int node = 0; node < n; node++)
            if(indegree[node] == 0)
                q.emplace(node);

        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            ++processed;
            order.emplace_back(node);

            for(auto neighbor: graph[node]) {
                --indegree[neighbor];
                if(indegree[neighbor] == 0)
                    q.emplace(neighbor);
            }
        }

        return processed < n ? vector<int>{} : order;
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {

        for(int node = 0; node < n; node++)
            if(group[node] == -1)
                group[node] = m++;

        vector<unordered_set<int> > group_graph(m), node_graph(n);

        vector<int> group_indegree(m, 0), node_indegree(n, 0);

        for(auto node = 0; node < n; node++) {

            int dst_group = group[node];

            for(auto src_node: beforeItems[node]) {
                int src_group = group[src_node];

                if(dst_group != src_group && !group_graph[src_group].count(dst_group)) {
                    group_graph[src_group].emplace(dst_group);
                    ++group_indegree[dst_group];
                }

                if(!node_graph[src_node].count(node)) {
                    node_graph[src_node].emplace(node);
                    ++node_indegree[node];
                }
            }
        }

        vector<int> ordered_nodes = topologicalSort(node_graph, node_indegree);

        vector<int> ordered_groups = topologicalSort(group_graph, group_indegree);

        vector<int> order;

        vector<vector<int> > group_ordered_nodes(m);
        for(auto node: ordered_nodes)
            group_ordered_nodes[group[node]].emplace_back(node);

        for(auto group: ordered_groups)
            for(auto node: group_ordered_nodes[group])
                order.emplace_back(node);

        return order;
    }
};
