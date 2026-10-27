class RLEIterator {
    vector<int> encoding;

    int curr = -1;

    int len = 0;
public:
    RLEIterator(vector<int>& encoding) {
        this->encoding = encoding;
        curr = 0;
        len = encoding.size();
    }

    int next(int n) {

        for(; curr < len && n > 0 && encoding[curr] < n; curr += 2) {

            if(encoding[curr] == 0)
                continue;
            n -= encoding[curr];
        }

        int element = -1;

        if(curr < len && encoding[curr] >= n) {

            encoding[curr] -= n;
            element = encoding[curr+1];

            if(encoding[curr] == 0)
                curr += 2;
        }
        return element;
    }
};
