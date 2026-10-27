class Solution {
public:

    int bfs(vector<vector<int>>& positions,int move) {

        int chessBoard[8][8];
        memset(chessBoard, 0, sizeof(chessBoard));
        bool isVal = false;
        for (vector<int> &pos : positions) {
            int x = pos[0] + pos[4] * pos[2] , y = pos[1] + pos[4] * pos[3];
            if (pos[4] > move) {
                isVal = true;
                x = pos[0] + move * pos[2], y = pos[1] + move * pos[3];
            }
            if (x < 0 || x > 7 || y < 0 || y > 7) return 0;
            chessBoard[x][y]++;
        }
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                if (chessBoard[i][j] > 1) return 0;
        int ret = 0;
        if (!isVal) ret = 1;
        else ret = bfs(positions, move + 1);
        return ret;
    }
    int dfs(int idx, vector<string>& pieces, vector<vector<int>>& positions) {
        if (idx >= pieces.size()) return bfs(positions, 0);
        int ret = 0;
        positions[idx].push_back(0);positions[idx].push_back(0);positions[idx].push_back(0);
        ret += dfs(idx + 1, pieces, positions);
        positions[idx].pop_back();positions[idx].pop_back();positions[idx].pop_back();

        if (pieces[idx] == "rook" || pieces[idx] == "queen") {
            for (int x = - 1; x <= 1; x++) if (x != 0) {
                for (int moves = 1; moves < 8; moves++) {
                    int dx = positions[idx][0] + moves * x;
                    if (dx >= 0 && dx < 8) {
                        positions[idx].push_back(x);positions[idx].push_back(0);positions[idx].push_back(moves);
                        ret += dfs(idx + 1, pieces, positions);
                        positions[idx].pop_back();positions[idx].pop_back();positions[idx].pop_back();
                    }
                }
            }
            for (int y = - 1; y <= 1; y++) if (y != 0) {
                for (int moves = 1; moves < 8; moves++) {
                    int dx = positions[idx][1] + moves * y;
                    if (dx >= 0 && dx < 8) {
                        positions[idx].push_back(0);positions[idx].push_back(y);positions[idx].push_back(moves);
                        ret += dfs(idx + 1, pieces, positions);
                        positions[idx].pop_back();positions[idx].pop_back();positions[idx].pop_back();
                    }
                }
            }
        }
        if (pieces[idx] == "bishop" || pieces[idx] == "queen") {
            for (int x = - 1; x <= 1; x++) if (x != 0) for (int y = -1; y <= 1; y++) if (y != 0) {
                for (int moves = 1; moves < 8; moves++) {
                    int dx = positions[idx][0] + moves * x;
                    int dy = positions[idx][1] + moves * y;
                    if (dx >= 0 && dx < 8 && dy >= 0 && dy < 8) {
                        positions[idx].push_back(x);positions[idx].push_back(y);positions[idx].push_back(moves);
                        ret += dfs(idx + 1, pieces, positions);
                        positions[idx].pop_back();positions[idx].pop_back();positions[idx].pop_back();
                    }
                }
            }
        }
        return ret;
    }
    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
        for (vector<int> &pos : positions)pos[0]--, pos[1]--;
        return dfs(0, pieces, positions);

    }
};
