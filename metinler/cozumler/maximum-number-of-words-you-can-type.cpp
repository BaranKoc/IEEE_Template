class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int> ch(26,0);

        for(char c: brokenLetters){
            ch[c-'a']=1;
        }

        stringstream s(text);
        string word;

        int count = 0,flag=0;
        while (s >> word){
            flag=0;
            for(char &c: word){

                if(ch[c-'a']==1){
                    flag=1;
                    break;
                }
            }

            if(flag==0)
                count++;
        }
        return count;
    }
};
