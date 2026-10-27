class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string, vector<int>> umap;

        for(int curr = 0; curr < wordlist.size(); curr++){

            umap[wordlist[curr]].push_back({curr});

            string tmp = wordlist[curr];
            transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);

            if(umap.find(tmp) == umap.end() && tmp != wordlist[curr]) umap[tmp].push_back({curr});

            for(int c_index = 0; c_index < tmp.size(); c_index++){
                char c = tmp[c_index];
                if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') tmp[c_index] = '_';
            }

            if(umap.find(tmp) == umap.end()) umap[tmp].push_back({curr});
        }

        for(int curr = 0; curr < queries.size(); curr++){
            string tmp = queries[curr];
            transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);

            if(umap.find(queries[curr]) != umap.end()){
                queries[curr] = (umap[queries[curr]].size() == 1) ? wordlist[umap[queries[curr]][0]] : wordlist[umap[queries[curr]][1]];
                continue;
            }

            if(umap.find(tmp) != umap.end() && tmp != queries[curr]){
                queries[curr] = wordlist[umap[tmp][0]];
                continue;
            }

            for(int c_index = 0; c_index < tmp.size(); c_index++){
                char c = tmp[c_index];
                if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') tmp[c_index] = '_';
            }

            if(umap.find(tmp) != umap.end()){
                queries[curr] = wordlist[umap[tmp][0]];
                continue;
            }

            queries[curr] = "";
        }

        return queries;
    }
};
