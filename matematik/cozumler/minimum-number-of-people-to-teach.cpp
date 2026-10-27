class Solution {
public:
    bool checkinvalid( int a, int b, vector<vector<int>>& languages){
        a--; b--;
        for( int i=0;i<languages[a].size();i++){
            if(find(languages[b].begin(), languages[b].end(), languages[a][i]) != languages[b].end()) return false;
        }
        return true;
    }

    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m= languages.size();
        vector<vector<int>> g(m+1, vector<int>(0));

        for( int i=0;i<friendships.size();i++){
            g[friendships[i][0]].push_back(friendships[i][1]);
            g[friendships[i][1]].push_back(friendships[i][0]);
        }

        vector<int> voters(m+1,0);
        int voterscount=0;
        for( int i=1;i<m+1;i++){
             for( int j=0;j<g[i].size();j++){
                if( checkinvalid(i, g[i][j], languages)){
                    voters[i]=1;
                    voterscount++;
                    break;
                }
            }
        }
        unordered_map<int,int> mappy;
        int maxvotes=0;

        for( int i=1;i<m+1;i++){
            if(voters[i]==1){
                for( int j: languages[i-1]){
                    mappy[j]++;

                    if(maxvotes<mappy[j]){
                        maxvotes= mappy[j];
                    }
                }
            }
        }
        return voterscount - maxvotes;
    }
};
