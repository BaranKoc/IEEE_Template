class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();

        int cols = n / rows;
        vector<vector<char>> mat(rows, vector<char>(cols, ' '));
        int i = 0, j = 0;
        int k = 0;

        string ans = "";

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                mat[i][j] = encodedText[k++];
            }
        }

        for(int k = 0; k < n - (rows * (rows - 1)) / 2; k++) {

            ans.push_back(mat[i++][j++]);

            if(i == rows || j == cols) {
                j -= (i - 1);
                i = 0;
            }
        }

        while(ans.back() == ' ')
            ans.pop_back();

        return ans;
    }
};
