class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](const vector<int> &curr, const vector<int> &next){
            return (curr[0]-curr[1]) < (next[0]-next[1]);
        });

        int sum = 0;
        for(int i=0; i<costs.size()/2; i++){
            sum+=costs[i][0];

        }
        for(int i=costs.size()/2; i<costs.size(); i++){
            sum+=costs[i][1];

        }

        return sum;
    }
};
