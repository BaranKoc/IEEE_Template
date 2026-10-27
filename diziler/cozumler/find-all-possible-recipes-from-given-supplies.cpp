class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {

        unordered_map<string,int>indegree;
        for(auto i:recipes)
            indegree[i]=0;

        unordered_map<string,vector<string>>graph;

        for(int i=0;i<recipes.size();i++){

            for(int j=0;j<ingredients[i].size();j++){

                if(find(supplies.begin(),supplies.end(),ingredients[i][j])==supplies.end()){

                    graph[ingredients[i][j]].push_back(recipes[i]);

                    indegree[recipes[i]]++;
                }
            }
        }
        queue<string>q;
        for(auto i:indegree){
            if(i.second==0)
                q.push(i.first);
        }
        vector<string>ans;

        while(!q.empty()){
            string front=q.front();
            q.pop();
            ans.push_back(front);
            for(auto i:graph[front]){
                indegree[i]--;
                if(!indegree[i])
                    q.push(i);
            }
        }
        return ans;
    }
};
