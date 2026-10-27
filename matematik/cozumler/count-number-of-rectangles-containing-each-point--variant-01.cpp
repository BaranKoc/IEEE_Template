class Solution {
public:

    int binsear(vector<int>& arr, int x){
        int l=0, r=arr.size()-1;

        int anstillnow=arr.size();

        while(l<=r){
            int m= l + (r-l)/2;

            if(arr[m]>=x){
                anstillnow=m;
                r=m-1;
            }
            else{
                l=m+1;
            }

        }

        return anstillnow;
    }

    vector<int> countRectangles(vector<vector<int>>& rect, vector<vector<int>>& points) {

        unordered_map<int, vector<int>> htl;

        for(int i=0; i<rect.size(); i++){
            htl[rect[i][1]].push_back(rect[i][0]);
        }

        for(int i=0; i<=100; i++){
            sort(htl[i].begin(), htl[i].end());
        }

        vector<int> ans;

        for(vector<int> p: points){
            int x=p[0], y=p[1];
            int ct=0;
            for(int j= y; j<=100; j++){
                if(htl.find(j)!=htl.end()){
                    ct+= htl[j].size()- binsear(htl[j], x);

                }
            }

            ans.push_back(ct);

        }

        return ans;
    }
};
