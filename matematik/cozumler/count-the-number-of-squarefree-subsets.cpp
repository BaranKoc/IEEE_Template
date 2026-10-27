int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
unordered_map<int,int> primeMap,freq;
int MOD=1e9+7;
int power(long long x, long long y, int p =  MOD)
{
    unsigned long long res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)  res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
class Solution {
private:
    int getMul(int mask,int num){
        for(auto& p:primes){
            if(num%p==0){
                if(mask&(1<<primeMap[p]))   return 0;
                num/=p;
                if(num%p==0)    return 0;
                mask|=(1<<primeMap[p]);
            }
        }
        return mask;
    }
    int construct(int prod_mask,vector<int>& nums,int idx){
        if(idx==nums.size())    return prod_mask!=0;

        int res=construct(prod_mask,nums,idx+1);

        int mask_when_multiplied=getMul(prod_mask,nums[idx]);
        if(mask_when_multiplied!=0) res=(res+1ll*freq[nums[idx]]*construct(mask_when_multiplied,nums,idx+1))%MOD;

        return res;
    }
public:
    int squareFreeSubsets(vector<int>& nums) {
        freq.clear();

        for(int i=0;i<10;i++)    primeMap[primes[i]]=i+1;
        for(auto& i:nums)   freq[i]++;

        set<int> st(nums.begin(),nums.end());
        nums.clear();
        for(auto& x:st) if(x>1)    nums.push_back(x);

        int numberOfSets=construct(0,nums,0)%MOD;

        int nonEmpty1sets=(power(2,freq[1])-1+MOD)%MOD;

        numberOfSets=(numberOfSets+1ll*numberOfSets*nonEmpty1sets%MOD+nonEmpty1sets)%MOD;

        return numberOfSets;

    }
};
