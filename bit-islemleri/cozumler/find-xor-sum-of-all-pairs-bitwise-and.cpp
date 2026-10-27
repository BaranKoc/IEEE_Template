class Solution {
public:

    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int m=arr1.size();
        int n=arr2.size();
        long int ans1=0,ans2=0;
        for(int i=0;i<m;i++)
        {
            ans1=ans1 ^ arr1[i];
        }
        for(int j=0;j<n;j++)
        {
            ans2=ans2 ^ arr2[j];
        }
        return ans1 & ans2;

    }
};
