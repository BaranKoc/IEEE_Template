class Solution {
public:
    int parents[1001];

    int findpar(int parents[], int to_find)
    {
        while(parents[to_find] != to_find)
            to_find = parents[to_find];

        return to_find;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        unordered_map<string, int> email_to_id;

        for(int i = 0; i < accounts.size(); i++)
        {
            parents[i] = i;

            for(int j = 1; j < accounts[i].size(); j++)
            {

                if(email_to_id.find(accounts[i][j]) != email_to_id.end())
                {
                    int parent1 = findpar(parents, i);
                    int parent2 = findpar(parents, email_to_id[accounts[i][j]]);

                    parents[parent1] = parent2;
                }
                else
                {
                    email_to_id[accounts[i][j]] = parents[i];
                }
            }
        }

            unordered_map<int, vector<string>> resultant_map;

            for(auto it: email_to_id)
            {
                int uniq_id = findpar(parents, it.second);
                resultant_map[uniq_id].push_back(it.first);
            }

            vector<vector<string>> ans;
            for(auto it: resultant_map)
            {
                vector<string> email = it.second;

                sort(email.begin(), email.end());

                email.insert(email.begin(), accounts[it.first][0]);

                ans.push_back(email);
            }
        return ans;
    }
};
