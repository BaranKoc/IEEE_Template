class Solution {
private:
    unordered_map<string, string> hash;
    string server = "http://tinyurl.com/";
    string all = "0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

public:

    string encode(string longUrl) {
        srand(time(NULL));
        string add = "";
        int ran = rand() % 10;
        int strsize = all.size();
        while(ran){
            int index = rand() % strsize;
            add += all[index];
            ran--;
        }

        hash[(server+add)] = longUrl;

        return (server + add);
    }

    string decode(string shortUrl) {
        return hash[shortUrl];
    }
};
