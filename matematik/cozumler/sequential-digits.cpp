class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string lf = to_string(low);
        string rt = to_string(high);

        vector<int> ans;
        for(int i = lf.size(); i <= rt.size(); i++){
            for(int st = 1; st <= 9; st++){
                string base(i, '0');
                for(int j = 0; j < i; j++){
                    base[j] += st + j;
                }

                if(base.back() <= '9'){
                    int num = stoi(base);
                     if(low <= num && num <= high){
                         ans.push_back(num);
                     }
                }
            }
        }

        return ans;
    }

};
