class Solution {
public:
    vector<int> earliestAndLatest(int n, int first, int second) {
        int minRound = INT_MAX, maxRound = INT_MIN;

        function<void(int,int,int,int)> dfs =
            [&](int deadMask,int i,int j, int curRound) {

            while (i < j and deadMask & (1<<i))
                i += 1;

            while (i < j and deadMask & (1<<j))
                j -= 1;

            if (i >= j)
                dfs(deadMask, 1, n, curRound + 1);

            else if (i == first and j == second)
                minRound = min(curRound,minRound),
                maxRound = max(curRound,maxRound);

            else{
                if (i != first and i != second)
                    dfs(deadMask | (1<<i), i+1, j-1, curRound);
                if (j != first and j != second)
                    dfs(deadMask | (1<<j), i+1, j-1, curRound);

            }
        };
        dfs(0,1,n,1);
        return {minRound, maxRound};
    }
};
