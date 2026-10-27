#include <algorithm>
#include <cstdint>
#include <functional>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

namespace ieee_template {

namespace flood_fill {
class Solution {
public:
    vector<vector<int>> paths = {{0,1},{0,-1},{-1,0},{1,0}};
    bool check(int i,int j , int n, int m){
        if(i>=n or i<0 or j>=m or j<0) return false;
        return true;
    }
    void solve(vector<vector<int>> &image, int sr, int sc, int color, int orig){
        int n = image.size(), m = image[0].size();
        image[sr][sc] = color;
        for(int i=0;i<4;i++){
            int new_sr = paths[i][0] + sr;
            int new_sc = paths[i][1] + sc;
            if(check(new_sr,new_sc,n,m)==true and image[new_sr][new_sc]==orig){
                solve(image, new_sr, new_sc, color,orig);
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color==image[sr][sc]) return image;
        int orig = image[sr][sc];
        solve(image, sr,sc,color, orig);
        return image;
    }
};
}

namespace spiral_traversal {
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
}

}
