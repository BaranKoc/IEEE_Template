class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = (int)arrival.size();

        set<int> freeServers;
        for (int i = 0; i < k; i++) freeServers.insert(i);

        vector<int> serverTaskCount(k, 0);

        set<pair<int, int>> workingServers;
        for (int i = 0; i < n; i++) {
            int startTime = arrival[i];

            while (!workingServers.empty() && workingServers.begin()->first <= startTime) {
                auto s = *workingServers.begin();
                workingServers.erase(workingServers.begin());
                freeServers.insert(s.second);
            }

            if (freeServers.empty()) continue;

            int serverIndex = -1;
            auto it = freeServers.lower_bound(i % k);
            if (it == freeServers.end()) {
                serverIndex = *freeServers.begin();
                freeServers.erase(freeServers.begin());
            } else {
                serverIndex = *it;
                freeServers.erase(it);
            }

            workingServers.insert({startTime + load[i], serverIndex});

            serverTaskCount[serverIndex]++;

        }

        vector<int> ret;
        int maxVal = *max_element(serverTaskCount.begin(), serverTaskCount.end());
        for (int i = 0; i < k; i++)
            if (maxVal == serverTaskCount[i]) ret.push_back(i);

        return ret;
    }
};
