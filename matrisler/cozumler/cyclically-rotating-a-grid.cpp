const vector<pair<int, int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

class Solution
{
protected:
    int n, m;

    int whichLayer(int x, int y) {
        if (x < 0 || y < 0 || x >= n || y >= m) return -1;
        int i = min(x, n - x - 1);
        int j = min(y, m - y - 1);
        return min(i, j);
    }

    void nextPos(int x, int y, int dir, int& nx, int& ny) {
        nx = x + directions[dir].first;
        ny = y + directions[dir].second;
    }

    void advancePosition(int& x, int& y, int& d) {
        int nx, ny;
        nextPos(x, y, d, nx, ny);
        if (whichLayer(nx, ny) != whichLayer(x, y)) {

            d = (d + 1) % 4;
            nextPos(x, y, d, nx, ny);
        }
        x = nx; y = ny;
    }

public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k)
    {

        if (grid.empty()) throw invalid_argument("empty grid");
        m = grid.size();
        n = grid[0].size();
        if (n == 0) throw invalid_argument("empty grid");
        if (k < 0) throw invalid_argument("negative k not accepted");

        if (k == 0) return grid;

        const int L = min(n, m) / 2;
        for (int l = 0; l < L; l++) {
            vector<int> v;

            int j = l, i = l;
            int d = 0;
            do {
                v.push_back(grid[j][i]);
                advancePosition(i, j, d);
            } while (!(i == l && j == l));

            j = l; i = l;
            d = 0;
            int off = k % v.size();
            do {
                grid[j][i] = v[off];
                off = (off + 1) % v.size();
                advancePosition(i, j, d);
            } while (!(i == l && j == l));
        }

        return grid;
    }
};
