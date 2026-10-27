class Solution {
public:
    using ll = long long;

    ll bs(ll low , ll high, ll fs){

        ll ans = 1;
        while(low<=high){
            ll mid = low + (high-low)/2;
            if(mid*(mid+1)>fs){
                high = mid-1;
            }
            else if(mid*(mid+1)==fs){
                return mid;
            }
            else{
                ans = mid;
                low = mid+1;
            }
        }
        return ans;
    }

    vector<long long> maximumEvenSplit(long long finalSum) {

        if(finalSum&1) return {};
        if(finalSum==4) return {4};
        if(finalSum==8) return {2,6};

        vector<ll> ans;

        ll idx = bs(1,finalSum/2,finalSum);

        ll start = 2, end = idx*2;

        for(int i = start; i<= (idx-1)*2; i+=2){
            ans.push_back(i);
        }

        if(idx*(idx+1)<finalSum){
            end = end + abs(finalSum - idx*(idx+1));
        }

        ans.push_back(end);
        return ans;
    }
};
