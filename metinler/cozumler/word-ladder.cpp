class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {

        unordered_set<string> wordSet;
        bool isEndWordPresent = false;
        for (string s:wordList)
        {

            if (!isEndWordPresent && s.compare(endWord) == 0)
            {
                isEndWordPresent = true;
            }
            wordSet.insert(s);
        }

        if (!isEndWordPresent)
        {
            return 0;
        }

        queue<string> q;
        q.push(beginWord);
        int level = 0;

        while (!q.empty())
        {
            level++;
            int numStringsInCurLevel = q.size();

            while (numStringsInCurLevel--)
            {
                string curStr = q.front();
                q.pop();

                for (int i=0; i<curStr.length(); i++)
                {
                    string tempStr = curStr;

                    for (char c='a'; c<='z'; c++)
                    {
                        tempStr[i] = c;
                        if (tempStr.compare(curStr) == 0)
                        {

                            continue;
                        }

                        if (tempStr.compare(endWord) == 0)
                        {
                            return level+1;
                        }
                        if (wordSet.find(tempStr) != wordSet.end())
                        {

                            q.push(tempStr);
                            wordSet.erase(tempStr);
                        }
                    }
                }
            }
        }

        return 0;
    }
};
