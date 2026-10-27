class Solution {
public:

    int check(string &s,unordered_map<string,int>&mp)
    {
        string temp;
        temp.push_back(s[0]);

        for(int i=1;i<s.size();i++)
        {
            if(s[i]=='/')
            {
                if(mp.count(temp))
                    return true;
                temp+=s[i];
            }
            else temp+=s[i];
        }
        mp[s]=1;
        return false;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
      unordered_map<string,int>mp;
      sort(folder.begin(),folder.end());
     vector<string>ans;

        for(auto it:folder)
        {
            if(!check(it,mp))
                ans.push_back(it);
        }

        return ans;

    }
};
