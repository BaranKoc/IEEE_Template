class Solution {
public:

    int travel(vector<vector<int>>& tr , int lvl , int ind) {

        if(ind >= tr[lvl].size())
            return INT_MAX;

        if(lvl == tr.size() - 1) {
            return tr[lvl][ind];
        }

        int s = travel(tr , lvl + 1, ind );
        int se = travel(tr , lvl + 1 , ind + 1);

        return min(s , se) + tr[lvl][ind];

    }

    int minimumTotal(vector<vector<int>>& triangle) {
        return travel(triangle , 0 , 0);
    }
};
