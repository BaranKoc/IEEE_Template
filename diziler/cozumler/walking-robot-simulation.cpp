class Solution {
public:

    vector<vector<int>> change= {
        {3,2},
        {2,3},
        {0,1},
        {1,0}
    };

    vector<vector<int>> sign = {
        {0,1},
        {0,-1},
        {1,0},
        {-1,0}
    };

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<vector<int>> s;
        for(int i = 0;i<obstacles.size();i++){
            s.insert(obstacles[i]);
        }
        int direction = 0;
        int ans = 0;
        int xi = 0,yi = 0;
        for(int i = 0;i<commands.size();i++){
            if(commands[i]<=9 && commands[i]>=1){
                int signx = sign[direction][0];
                int signy = sign[direction][1];
                while(commands[i]){
                    xi += signx;
                    yi += signy;
                    if(s.count({xi,yi})){
                        xi -= signx;
                        yi -= signy;
                        break;
                    }
                    commands[i]--;
                }
            }
            else{
                direction = change[direction][commands[i]+2];
            }
            ans = max(ans,xi*xi+yi*yi);
        }
        return ans;
    }
};
