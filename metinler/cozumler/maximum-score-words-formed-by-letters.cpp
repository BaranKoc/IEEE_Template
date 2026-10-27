class Solution {
public:
    int calc(vector<string>& words,map<char,int>&m,vector<int>& score,int i){
        int maxi=0;
        if(i==words.size())
            return 0;
        map<char,int>m1=m;
        int c=0;
        for(int j=0;j<words[i].length();j++){
            if(m1.find(words[i][j])==m1.end()||m1[words[i][j]]==0){
                c=-1;
                break;
            }
            c+=score[words[i][j]-'a'];
            m1[words[i][j]]--;
        }
        if(c!=-1)
          maxi=c+(calc(words,m1,score,i+1));
        return max(maxi,calc(words,m,score,i+1));

}
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        map<char,int>m;
        for(auto i:letters)
            m[i]++;
        return calc(words,m,score,0);
    }
};
