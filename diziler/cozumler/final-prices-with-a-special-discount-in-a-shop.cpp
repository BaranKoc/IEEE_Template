class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res;
        for(int i=0;i<prices.size();i++)
        {
            res.push_back(prices[i]);
            for(int j=i+1;j<prices.size();j++)
            {
                if(prices[j]<=prices[i])
                {
                    res[i] = prices[i]-prices[j];
                    break;
                }
            }
        }
        return res;
    }
};
