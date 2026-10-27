class Solution {
public:
    string smallestGoodBase(string n) {
        string ans;
        long long nn = stol(n);

        for (int i=62;i>2;i--){

            long long k = pow(nn,1.0/(i-1));
            if (k==1) continue;

            long long sum = 1,kk=1;

            for (int j=1;j<i;j++){
                kk*=k;
                sum+=kk;
            }

            if (sum==nn) return to_string(k);
        }

        return to_string(nn-1);
    }
};
