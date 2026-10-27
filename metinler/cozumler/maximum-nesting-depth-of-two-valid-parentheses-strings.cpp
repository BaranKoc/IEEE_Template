class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {

        vector<int> indexA, indexB, res(seq.length(), 0 );

        int i = 0;
        int addToA = 0, addToB = 0;
        while(i < seq.length()){
            if(seq[i] == '('){
                if(addToA <= addToB){

                    indexA.push_back(i);
                    addToA ++;
                }else{
                    indexB.push_back(i);
                    addToB++;
                }
            }else{

                if(addToA >= addToB){
                    addToA--;
                    indexA.push_back(i);
                }else{
                    indexB.push_back(i);
                    addToB--;
                }
            }
           i++;
        }
         for(i = 0; i < indexB.size(); i++){
                res[indexB[i]] = 1;
            }
         return res;
    }
};
