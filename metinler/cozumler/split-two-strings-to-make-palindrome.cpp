class Solution {
public:
    bool ispalind(string x, int i, int j){
        while(i<j){
            if(x[i]!=x[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    bool checkpositions(string a, string b){
        int i=0,j=b.size()-1;
        while(i<j){
            if(a[i]!=b[j]) break;
            i++;
            j--;
        }

        return ispalind(a,i,j) || ispalind(b,i,j);
    }
    bool checkPalindromeFormation(string a, string b) {

        return checkpositions(a,b)||checkpositions(b,a);
    }
};
