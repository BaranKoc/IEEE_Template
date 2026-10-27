class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        multiset<int> ls;
        set<int> ins;
        int n = s.length();
        ins.insert(n);

        for (int i = 0, j = 1; i < n;) {
            while (j < n && s[j] == s[j-1]) ++j;
            ins.insert(i);
            ls.insert(j-i);
            i = j++;
        }

        vector<int> ans;
        for (int i = 0; i < queryIndices.size(); ++i) {

            if (queryCharacters[i] == s[queryIndices[i]]) {
                ans.push_back(*ls.rbegin());
                continue;
            }

            auto it = prev(ins.upper_bound(queryIndices[i]));
            int oldl = *next(it) - *it;
            ls.erase(ls.find(oldl));

            ins.insert(queryIndices[i]);
            ins.insert(queryIndices[i] + 1);
            if (*it != queryIndices[i]) ls.insert(queryIndices[i] - *it);
            ls.insert(1);
            if (oldl - (queryIndices[i] - *it + 1)) ls.insert(oldl - (queryIndices[i] - *it + 1) );

            s[queryIndices[i]] = queryCharacters[i];

            it = ins.find(queryIndices[i]);

            if (queryIndices[i] + 1 < n && s[queryIndices[i]] == s[queryIndices[i] + 1]) {
                ls.erase(ls.find(*next(it, 2) - *next(it)));
                ls.erase(ls.find(1));
                ins.erase(next(it));
                ls.insert(*next(it) - *it);
            }

            if (it != ins.begin() && s[queryIndices[i]] == s[queryIndices[i] - 1]) {
                ls.erase(ls.find(*next(it) - *it) );
                ls.erase(ls.find(*it - *prev(it)) );
                ls.insert(*next(it) - *prev(it));
                ins.erase(it);
            }
            ans.push_back(*ls.rbegin());

        }
        return ans;
    }
};
