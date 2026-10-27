class SnapshotArray {
    int timestamp;
    unordered_map<int, vector<int>> toSnaps, toValues;
public:
    SnapshotArray(int length) {
        timestamp = 0;
    }

    void set(int index, int val) {
        if (toSnaps.count(index) == 0) {

            toSnaps[index].push_back(-1);

            toValues[index].push_back(0);
        }

        if (toSnaps[index].back() == timestamp) {
            toValues[index].back() = val;
        }

        else {
            toSnaps[index].push_back(timestamp);
            toValues[index].push_back(val);
        }
    }

    int snap() {
        return timestamp++;
    }

    int get(int index, int snap_id) {

        if (toSnaps.count(index) == 0) return 0;
        auto& snaps = toSnaps[index];
        int lo = 0, hi = snaps.size()-1;
        while (lo < hi) {
            int m = lo + (hi - lo)/2;
            if (snaps[m] >= snap_id) hi = m;
            else lo = m + 1;
        }

        if (snaps[lo] > snap_id) lo--;

        return toValues[index][lo];
    }
};
