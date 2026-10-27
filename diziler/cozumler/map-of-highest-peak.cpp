class Solution {
public:

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int r = isWater.size();
        int c = isWater[0].size();
        queue <pair<int,int>> curr;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {

                if (isWater[i][j] == 0) {
                    isWater[i][j] = -1;
                }

                else {
                    isWater[i][j] = 0;
                    curr.push({i, j});
                }
            }
        }

        int hill = 0;
        while (!curr.empty()) {
            int len = curr.size();

            for (int k = 0; k < len; k++) {

                pair <int, int> fnt = curr.front(); curr.pop();
                int i = fnt.first, j = fnt.second;

                if (i > 0 && isWater[i - 1][j] == -1) {
                    isWater[i - 1][j] = hill + 1;
                    curr.push({i-1, j});
                }

                if ((i < r - 1) && (isWater[i + 1][j] == -1)) {
                    isWater[i + 1][j] = hill + 1;
                    curr.push({i+1, j});
                }

                if (j > 0 && (isWater[i][j - 1] == -1)) {
                    isWater[i][j - 1] = hill + 1;
                    curr.push({i, j-1});
                }

                if ((j < c - 1) && (isWater[i][j + 1] == -1)) {
                    isWater[i][j + 1] = hill + 1;
                    curr.push({i, j+1});
                }
            }

            hill += 1;
        }

        return isWater;
    }
};
