class Solution {
public:
    int result = 0;
    int n = 0;
    int maximumGood(vector<vector<int>>& statements) {
        n = statements.size();
        string cur = "";
        dfs(statements, cur, 0, 0);
        return result;
    }

    void dfs(vector<vector<int>>& statements, string& cur, int index, int goodPersonCount){
        if(index == n){

            if(isValid(cur, statements)) result = max(goodPersonCount, result);
            return;
        }

        cur.push_back('1');
        dfs(statements, cur, index+1, goodPersonCount+1);

        cur.back() = '0';
        dfs(statements, cur, index+1, goodPersonCount);

        cur.pop_back();
    }

    bool isValid(string& cur, vector<vector<int>>& statements){

        for(int i=0; i<n; i++){
            if(cur[i] == '1'){

                for(int j=0; j<n; j++){
                    if(statements[i][j] != 2 && statements[i][j] != cur[j] - '0') return false;
                }
            }
        }

        return true;
    }
};
