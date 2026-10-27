class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int>sk;
        vector<int>res;
        vector<int>temp;
        int ss=0;
        int mins;
        for(int i=0;i<s.length();i++){
            if(s[i]==c)

             sk.push_back(i);
        }
        for(int i=0;i<s.length();i++){
            for(int j=0;j<sk.size();j++){

                mins=abs(sk[j]-i);
                temp.push_back(mins);
            }

            int min=temp[0];
            for(auto i:temp){
                if(i<min){
                    min=i;
                }
            }
            res.push_back(min);
            temp.clear();

        }

        return res;
    }
};
