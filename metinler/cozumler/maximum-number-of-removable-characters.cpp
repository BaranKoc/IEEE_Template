class Solution {
public:
    bool isSubSequence(string str1, string str2){
        int j = 0,m=str1.size(),n=str2.size();
        for (int i = 0; i < n && j < m; i++)
            if (str1[j] == str2[i])
                j++;
        return (j == m);
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        string copy=s;
        int left = 0, right =removable.size();
        while (left <= right) {
            int mid = (left+right)/2;
            for(int i=0;i<mid;i++) copy[removable[i]]='*';
            if (isSubSequence(p,copy))

                left = mid+1;
            else {

                for(int i=0;i<mid;i++) copy[removable[i]] = s[removable[i]];
                right = mid-1;
            }
        }
        return right;
    }
};
