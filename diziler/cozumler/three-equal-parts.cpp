class Solution {
public:
    vector<int> threeEqualParts(vector<int>& v) {
        vector<int> one;
        int n=v.size();
        for(int i=0;i<n;i++){
            if(v[i]==1) one.push_back(i+1);
        }
        if(one.size()==0){
            return {0,2};
        }
        if(one.size()%3)    return {-1,-1};

        int ext=n-one.back(),sz=one.size();
        int gap1=one[sz/3]-one[sz/3-1]-1,gap2=one[2*sz/3]-one[2*sz/3-1]-1;

        if(gap1<ext || gap2<ext)    return {-1,-1};

        string s1,s2,s3;
        for(int i=0;i<=one[sz/3-1]+ext-1;i++){
            if(s1.length()>0 || v[i])   s1+=to_string(v[i]);
        }

        for(int i=one[sz/3-1]+ext;i<=one[2*sz/3-1]+ext-1;i++){
            if(s2.length()>0 || v[i])   s2+=to_string(v[i]);
        }

        for(int i=one[2*sz/3-1]+ext;i<=n-1;i++){
            if(s3.length()>0 || v[i])   s3+=to_string(v[i]);
        }

        if(s1==s2 && s2==s3)    return {one[sz/3-1]+ext-1,one[2*sz/3-1]+ext};
        return {-1,-1};
    }
};
