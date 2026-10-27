class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();

        int g=arr[n-1];

        arr[n-1]=-1;
        for(int i=n-2;i>=0;i--)
        {

            int h=arr[i];

            arr[i]=g;

            if(h>g)
            {
                g=h;
            }
        }

     return arr;
    }
};
