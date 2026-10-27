class Trie {
public:
    struct tr {
        bool isword;
        vector<tr*> next;
        tr() {
            next.resize(26, NULL);
            isword = false;
        }
    };

    tr *root;
    Trie() {
        root = new tr();
    }

    void insert(string word) {
        tr *cur = root;

        for(auto c: word) {

            if(cur->next[c-'a'] == NULL) {
                cur->next[c-'a'] = new tr();
            }
            cur = cur->next[c-'a'];
        }

        cur->isword = true;
    }

    bool search(string word) {
        tr *cur = root;

        for(auto c: word) {

            if(cur->next[c-'a'] == NULL) {
                return false;
            }

            cur = cur->next[c-'a'];
        }

        if(cur->isword){
            return true;
        }
        return false;
    }

    bool startsWith(string prefix) {
        tr *cur = root;

        for(auto c: prefix) {
            if(cur->next[c-'a'] == NULL) {
                return false;
            }

            cur = cur->next[c-'a'];
        }

        return true;
    }
};
