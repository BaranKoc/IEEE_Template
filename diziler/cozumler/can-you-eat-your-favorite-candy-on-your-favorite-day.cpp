class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {

        vector <bool> outcome;

        vector <long int> candyIndex(candiesCount.size());
        long int x = 0;
        for (int i =0; i< candiesCount.size();i++){
            candyIndex[i] = x;
            x += candiesCount[i];
        }

        for (int i =0;i< queries.size();i++){

            long int highBound = (long int) queries[i][2]*(queries[i][1]+1), lowBound = queries[i][1]+1;

            bool answer = candyIndex[queries[i][0]] < highBound && (candyIndex[queries[i][0]] + candiesCount[queries[i][0]]-1) >= (lowBound -1);
            outcome.push_back(answer);
        }
        return outcome;
    }
};
