class Solution {
public:
    vector<long long> sumOfThree(long long num) {

        long long lo = -1;
        long long hi = num;
        while(lo<=hi){
            long long mid = lo +(hi-lo)/2;
            long long val = 3*mid+3;
            if(val == num){
                return {mid,mid+1,mid+2};
            }
            else if(val>num){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }

        return {};
    }
};
