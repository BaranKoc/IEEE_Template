class Solution {
public:
     int arr[101]={0};
    vector<int> done[101];

    bool check(vector<int>& a){
      for(int i:a){
          if(arr[i]!=-1){
              return 1;
          }
      }
        return 0;
    }
int minDeletionSize(vector<string>& strs) {

        int ans=0;

     for(int i=0;i<strs[0].size();i++){

         for(int j=0;j<strs.size()-1;j++){

           if((done[j].size()==0 || check(done[j])==0) && strs[j][i]>strs[j+1][i]){

                ans++;
               arr[i]=-1;
                break;
            }
             if(strs[j][i]<strs[j+1][i]){

                 done[j].push_back(i);
             }
         }

     }

        return ans;
    }

};
