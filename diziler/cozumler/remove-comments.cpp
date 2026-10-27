class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        string cur="";
        vector<string> out;
        bool comm=false;

        for(string s: source){
            for(int j=0; j<s.size(); j++){

                if(!comm && s[j]=='/' && s[j+1]=='*'){
                    comm = true;
                    j++;
                }

                else if(!comm && s[j]=='/' && s[j+1]=='/') break;

                else if(comm && s[j]=='*' && s[j+1]=='/') {
                    comm=false;
                    j++;
                }

                else if (!comm)
                    cur+=s[j];
            }

            if(!comm && cur.size()){
                out.push_back(cur);
                cur="";
            }
        }
        return out;
    }
};
