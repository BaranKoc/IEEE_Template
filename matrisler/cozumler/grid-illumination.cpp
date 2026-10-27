class Solution {
public:

    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {

        vector<int>ans;
        unordered_map<int,int>row,col,mainDiag,antiDiag;
        set<pair<int,int>>s;

        for(auto &l : lamps){
            int x = l[0],y=l[1];

            if(s.find({x,y}) == s.end())
            {
                row[x]++;
                col[y]++;
                antiDiag[x+y]++;
                mainDiag[x-y]++;
                s.insert({x,y});
            }
        }

        for(auto &q : queries)
        {

            int x = q[0],y = q[1];
            if(row[x]>0 or col[y]>0 or antiDiag[x+y]>0 or mainDiag[x-y]>0)
            {

                ans.push_back(1);

                for(int i=-1;i<=1;i++){
                    for(int j=-1;j<=1;j++){

                        int nx = x+i;
                        int ny = y+j;

                        if(nx >= 0 and nx < n and ny >=0 and ny < n and s.find({nx,ny})!=s.end())
                        {
                            row[nx]--;
                            col[ny]--;
                            antiDiag[nx+ny]--;
                            mainDiag[nx-ny]--;
                            s.erase({nx,ny});
                        }
                    }
                }
            }
            else
                ans.push_back(0);
        }
        return ans;
    }
};
