class Solution {
private:

    bool isSubSeq(string &s,string &word){
        int start=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==word[start]){

                if(++start==word.size()){
                    return true;
                }
            }
        }
        return false;
    }
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans="";
        for(string word:dictionary){
            if(word.size()>=ans.size() and isSubSeq(s,word)){
                if(word.size()>ans.size()){
                    ans=word;
                } else if(word.size()==ans.size() and word<ans){
                    ans=word;
                }
            }
        }
        return ans;
    }
};
