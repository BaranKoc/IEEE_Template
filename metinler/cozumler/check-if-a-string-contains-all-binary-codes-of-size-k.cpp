class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=pow(2,k),m=s.size();
        vector<bool>check(n,0);

        int val=0;
        int i=0,j=0;

        while(j<m)
        {
            val=val*2+(s[j]-'0');

            if(j-i+1<k)
                j++;
            else if(j-i+1==k)
            {
                check[val]=true;
                val=val-(s[i]-'0')*(pow(2,k-1));
                i++;
                j++;
            }
        }

        for(int l=0;l<n;l++)
        {
            if(check[l]==false)
                return false;
        }

        return true;
    }
};
