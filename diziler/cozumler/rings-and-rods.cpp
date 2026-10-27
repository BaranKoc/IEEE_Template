class Solution {
public:
    int countPoints(string rings) {

        int n=rings.length();

        vector<int>vp(10,0);
        for(int i=0;i<n;i+=2)
        {
            char col=rings[i];
            vp[rings[i+1]-'0']|=(col=='R'? 1: col =='G' ? 2 : 4);

        }
        int count=0;
        for(int i=0;i<10;i++)
        {
            if(vp[i]==7)
            {
                count++;
            }
        }
        return count;

    }
};
