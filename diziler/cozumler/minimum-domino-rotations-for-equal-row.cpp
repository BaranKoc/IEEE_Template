class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> freq(7, 0);

        int n = tops.size();
        int tile = -1

        for(int i=0; i<n; ++i){
            int top = tops[i];
            int bottom = bottoms[i];

            freq[top]++;
            if(top != bottom){
                freq[bottom]++;
            }

            if(freq[top] == n){
                tile = top;
            }
            if(freq[bottom] == n){
                tile = bottom;
            }
        }

        if(tile == -1){
            return -1;
        }

        int tilesTop = 0;
        int tilesBottom = 0;
        for(int i=0; i<n; ++i){
            if(tops[i] == bottoms[i])continue;

            if(tops[i] == tile){
                tilesTop++;
            }
            if(bottoms[i] == tile){
                tilesBottom++;
            }
        }

      return tilesTop < tilesBottom ? tilesTop : tilesBottom;
    }
};
