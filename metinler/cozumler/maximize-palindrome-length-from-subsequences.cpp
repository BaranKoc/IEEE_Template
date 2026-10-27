class Solution {
public:

    vector<vector<int>> v;

    int boundary,l,ans;

    int find(string &s,int i,int j)
    {

        if(i>j) return 0;

        if(v[i][j]!=-1) return v[i][j];

        if(i==j)
        {
            return v[i][j]=1+find(s,i+1,j-1);
        }

        if(s[i]==s[j])
        {

            int k=v[i][j]=2+find(s,i+1,j-1);

            if(i<boundary && j>=boundary)
            {
                ans=max(ans,k);
            }
            return k;
        }

        else
        {
            return v[i][j]=max(find(s,i+1,j),find(s,i,j-1));
        }
    }

    int longestPalindrome(string word1, string word2) {

        boundary=word1.size();

        word1+=word2;

        l=word1.length();

        v=vector<vector<int>> (l+1,vector<int> (l+1,-1));

        int k=find(word1,0,l-1);

        return ans;
    }
};
