class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;

        for(int i = 0 ; i < words.size(); i++)
        {
            for(int j = 0; j < words.size(); j++)
            {
                if(i != j && words[j].find(words[i]) != -1)
                {
                    if(!count(res.begin(),res.end(), words[i]))
                        res.push_back(words[i]);
                    else
                        continue;
                }
            }
        }

        return res;
    }
};
