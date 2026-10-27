class Solution {
public:
    bool canArrange(vector<int>& arr, int k)
    {
        unordered_map<int,int>memo;

        for(auto curr : arr)
        {
            int remainder = ((curr%k)+k)%k;
            memo[remainder]++;
        }

        for(int i =1; i<=k/2; i++)
        {
            if(memo[i] != memo[k-i])
                return false;
        }
        if(memo[0]%2 != 0)
            return false;
        return true;
    }
};
