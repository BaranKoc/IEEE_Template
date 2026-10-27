class Solution {

public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        if(N == 0) return cells;
        prison(cells, 1);
        prison(cells, (N - 1) % 14);
        return cells;
    }
    void prison(vector<int>& cells, const int& N){
        for(int i = 0; i < N; i++){
            vector<int> v(8,0);
        for(int i = 1; i < 7; i++)
            if(cells[i - 1] == cells[i + 1])
                v[i] = 1;
            else v[i] = 0;
        cells = v;
        }
    }
};
