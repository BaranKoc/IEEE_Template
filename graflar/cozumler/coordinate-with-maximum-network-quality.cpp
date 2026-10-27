class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int n = towers.size();
        int sum;
        int ans = 0;
        pair<int,int> ansCoor;

        for(int x = 0; x <= 50; x++){
            for(int y = 0; y <= 50; y++){
                sum = 0;
                for(const auto it : towers){
                    int xa = it[0];
                    int ya = it[1];
                    int qa = it[2];

                    int distance = pow(x - xa, 2) + pow(y - ya, 2);
                    if(distance > radius * radius) {
                        continue;
                    }

                    sum += (int)(qa / (1 + sqrt(distance)));
                }

                if(sum > ans){
                    ans = sum;
                    ansCoor = {x,y};
                }
            }
        }
        return vector<int>{{ansCoor.first, ansCoor.second}};
    }
};
