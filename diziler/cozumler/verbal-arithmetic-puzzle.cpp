class Solution {
    int limit = 0;
    unordered_map<char, int> c2i;
    unordered_map<int, char> i2c;
    bool helper(vector<string> &words, string &result, int digit, int wid, int sum)
    {
        if(digit==limit)
            return sum == 0;
        if(wid==words.size())
        {
            if(c2i.count(result[digit])==0 && i2c.count(sum%10)==0)
            {
                if(sum%10==0 && digit+1 == limit)
                    return false;
                c2i[result[digit]] = sum%10;
                i2c[sum%10] = result[digit];
                bool tmp = helper(words, result, digit+1, 0, sum/10);

                c2i.erase(result[digit]);
                i2c.erase(sum%10);
                return tmp;
            }
            else if(c2i.count(result[digit]) && c2i[result[digit]] == sum%10)
            {
                if(digit+1 == limit && c2i[result[digit]]==0)
                    return false;
                return helper(words, result, digit+1, 0, sum/10);
            }
            else
                return false;
        }
        if(digit>=words[wid].length())
            return helper(words, result, digit, wid+1, sum);

        if(c2i.count(words[wid][digit]))
        {
            if(digit+1 == words[wid].length() && words[wid].length() > 1 && c2i[words[wid][digit]]==0)
                return false;
            return helper(words, result, digit, wid+1, sum+c2i[words[wid][digit]]);
        }
        for(int i=0; i<10; i++)
        {
            if(digit+1==words[wid].length() && i==0 && words[wid].length()>1)
                continue;
            if (i2c.count(i))
                continue;
            c2i[words[wid][digit]] = i;
            i2c[i] = words[wid][digit];
            bool tmp = helper(words, result, digit, wid+1, sum+i);
            c2i.erase(words[wid][digit]);
            i2c.erase(i);
            if(tmp)
                return true;
        }
        return false;
    }

public:
    bool isSolvable(vector<string>& words, string result) {
        limit = result.length();
        for(auto s:words)
        {
            if(s.length()>limit)
                return false;
        }
        for(auto &s:words)
        {
            reverse(s.begin(), s.end());
        }
        reverse(result.begin(), result.end());
        return helper(words, result, 0, 0, 0);
    }
};
