class StreamChecker {
    struct Trie {
        Trie* suffixLink;
        int id = -1;
        map<char, Trie*> next;
    };
public:
    Trie* root;
    Trie* queryPtr;
    int uniqueIds = 0;

    StreamChecker(vector<string>& words) {
        root = new Trie();

        for (string& word: words) {
            Trie* p = root;
            for (char c: word) {
                if (p->next.find(c) == p->next.end()) {
                    p->next.insert({ c, new Trie() });
                }
                p = p->next.at(c);
            }
            if (p->id == -1) {
                p->id = uniqueIds++;
            }
        }

        queue<Trie*> q;
        for (pair<char, Trie*> itr: root->next) {
            q.push(itr.second);
            itr.second->suffixLink = root;
        }

        while (q.size()) {
            Trie* curr = q.front();
            q.pop();
            for (pair<char, Trie*> e: curr->next) {
                char c = e.first;
                Trie* node = e.second;

                Trie* ptr = curr->suffixLink;
                while (ptr != root && ptr->next.find(c) == ptr->next.end()) {
                    ptr = ptr->suffixLink;
                }

                node->suffixLink = ptr->next.find(c) != ptr->next.end() ? ptr->next.at(c) : root;

                if (node->suffixLink->id != -1) {
                    node->id = node->suffixLink->id;
                }
                q.push(node);
            }
        }

        queryPtr = root;
    }

    bool query(char letter) {

        while (queryPtr != root && queryPtr->next.find(letter) == queryPtr->next.end()) {
            queryPtr = queryPtr->suffixLink;
        }
        queryPtr = queryPtr->next.find(letter) != queryPtr->next.end() ? queryPtr->next.at(letter) : root;

        return queryPtr->id != -1;
    }
};
