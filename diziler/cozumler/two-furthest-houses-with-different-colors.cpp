class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int Max = INT_MIN;
        int N = colors.size();

        int j=N;
        while(--j>=0 && colors[0]==colors[j]) { }
        Max = abs(j-0);

        j=-1;
        while(++j<N && colors[N-1]==colors[j]) { }
        Max = max(Max, abs(j-(N-1)));

        return Max;
    }
};
