'''
class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int n=s.size();
        long long int sum=0;
        long long int p=1;

        for(int i=0;i<k;i++){
                sum=(sum+((s[n-k+i]-'a'+1)*p));
                if(i!=k-1)
                    p=(p*power)%modulo;
        }

        int res=n-k;

        for(int i=n-1;i>=k;i--)
		{

                sum-=(s[i]-'a'+1)*(p%modulo);

                sum=sum%modulo;

                sum=sum*(power%modulo);

                sum+=s[i-k]-'a'+1;

            while(sum%modulo<0){
                sum=sum+modulo;
            }
            if(sum%modulo==hashValue){
                res=i-k;
            }
        }
        return s.substr(res,k);
    }
};
'''
