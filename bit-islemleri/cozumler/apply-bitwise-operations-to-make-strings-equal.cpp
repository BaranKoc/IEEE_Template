class Solution {
public:
    bool makeStringsEqual(string s, string t) {
        int a=0, b=0;
        for(char c:s)
        {
            if(c=='1')
            a++;
        }
        for(char c:t)
        {
            if(c=='1')
            b++;
        }
        if(a==0 && b==0)
        return true;
        if(a==0 && b!=0)
        return false;
        if(b==0)
        return false;
        return true;
    }
};
