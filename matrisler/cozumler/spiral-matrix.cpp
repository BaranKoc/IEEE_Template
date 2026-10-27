class Solution {
public:

    vector<int> _res;
    vector<vector<bool>> _visited;

    void spin(vector<vector<int>>& matrix, int direction, int i, int j) {

        _visited[i][j] = true;
        _res.push_back(matrix[i][j]);

        switch (direction){

            case 0:
                if ( j+1 >= matrix[0].size() || _visited[i][j+1]) {
                    direction = 1;
                    i++;
                } else {
                    j++;
                }
                break;

            case 1:
                if ( i+1 >= matrix.size() || _visited[i+1][j]) {
                    direction = 2;
                    j--;
                } else {
                    i++;
                }
                break;

            case 2:
                if ( j == 0 || _visited[i][j-1]) {
                    direction = 3;
                    i--;
                } else {
                    j--;
                }
                break;

            case 3:
                if ( i == 0 || _visited[i-1][j]) {
                    direction = 0;
                    j++;
                } else {
                    i--;
                }
                break;
        }
        if ( i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() ) {
            return;
        }
        if ( _visited[i][j] ) {
            return;
        }
        spin(matrix, direction, i, j);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        _res.clear();
        _visited = vector<vector<bool>>(matrix.size(), std::vector<bool>(matrix[0].size(), false));
        spin(matrix, 0, 0, 0);
        return _res;
    }
};
