class Solution {

public:
string maxValue(string s, int x) {
    int p=0,flag=0;
    char ch='0'+x;
    string str;

    if(s[0]=='-')
    {
	     for(int i=1;i<s.size();i++)
        {
          if(ch<s[i] && !flag){
            str+=ch;
            str+=s[i];
            flag=1;
          }
          else
           str+=s[i];
        }
        if(!flag) str+=ch;
        return '-'+str;
    }

    for(int i=0;i<s.size();i++)
    {
       if(ch>s[i] && !flag){
         str+=ch;
         str+=s[i];
         flag=1;
       }
       else
        str+=s[i];
    }
    if(!flag) str+=ch;
    return str;
  }
};
