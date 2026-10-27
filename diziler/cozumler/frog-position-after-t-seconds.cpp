class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        unordered_map<int, vector<int>> adjList;
        for(const auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        queue<pair<int, double>> Q;
        Q.push({1, 1.0});
        int time = 0;
        vector<int> visited(n+1, false);

        while(not Q.empty()) {
            int size = Q.size();

            if (time > t) break;

            while(size--) {
                auto pp = Q.front(); Q.pop();
                int node = pp.first;
                double prob = pp.second;

                visited[node] = true;

                int nbrCount = 0;
                for(auto& nbr : adjList[node]) {
                    if (not visited[nbr]) nbrCount++;
                }

                if (node == target) {
                    if (time == t) return prob;
                    if (time < t) {

                        if (nbrCount > 0) return 0.0;

                        return prob;
                    }
                }

                for(auto& nbr : adjList[node]) {
                    if (not visited[nbr]) {

                        Q.push({nbr, (prob * (1.0/nbrCount))});
                    }
                }
            }

            time++;
        }

        return 0.0;
    }
};
