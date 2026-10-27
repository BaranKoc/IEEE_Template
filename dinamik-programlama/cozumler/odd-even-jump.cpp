class Solution {
private:
    void tryOddJump(const int idx,
                    const int val,
                    std::map<int, int>& visitedNode,
                    vector<int>& oddJumpsDP,
                    vector<int>& evenJumpsDP) {

        auto jumpPoint = visitedNode.lower_bound(val);

        if(jumpPoint != visitedNode.end()) oddJumpsDP[idx] = evenJumpsDP[jumpPoint->second];
    }

    void tryEvenJump(const int idx,
                     const int val,
                     std::map<int, int>& visitedNode,
                     vector<int>& oddJumpsDP,
                     vector<int>& evenJumpsDP) {

        auto jumpPoint = visitedNode.upper_bound(val);

        if(jumpPoint != visitedNode.begin())
            evenJumpsDP[idx] = oddJumpsDP[std::prev(jumpPoint)->second];
    }
public:
    int oddEvenJumps(vector<int>& arr) {
        const size_t n = arr.size();
        vector<int> oddJumpsDP(n, 0);
        vector<int> evenJumpsDP(n, 0);
        oddJumpsDP[n-1] = 1;
        evenJumpsDP[n-1] = 1;
        std::map<int, int> visitedNode;
        visitedNode[arr[n-1]] = n-1;

        int res = 1;
        for(int i=n-2; i>=0; --i) {
            tryOddJump(i, arr[i], visitedNode, oddJumpsDP, evenJumpsDP);
            tryEvenJump(i, arr[i], visitedNode, oddJumpsDP, evenJumpsDP);

            if(oddJumpsDP[i] == 1) ++res;
            visitedNode[arr[i]] = i;
        }

        return res;
    }
};
