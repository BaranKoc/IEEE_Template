static int x = []() {
std::ios::sync_with_stdio(false);
cin.tie(nullptr);
return 0; }();

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<bool> rows(n,false),cols(m,false);
        for(auto index: indices){
            rows[index[0]] = rows[index[0]] ^ true;
            cols[index[1]] = cols[index[1]] ^ true;
        }

        int r(0),c(0);
        for(int i(0);i<n;i++){
            if(rows[i]) r++;
        }

        for(int i(0);i<m;i++){
            if(cols[i]) c++;
        }
        return r*(m-c) + c*(n-r);
    }
};
