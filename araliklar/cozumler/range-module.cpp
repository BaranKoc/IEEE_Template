class RangeModule {
private:
    struct Interval {
        const bool operator<(const Interval& b) const {

            return tie(start, end) < tie(b.start, b.end);
        }

        int start = -1, end = -1;
        Interval(int start, int end): start(start), end(end) {};
    };

    set<Interval> intervals;
public:
    RangeModule() {

    }

    void addRange(int left, int right) {
        Interval interval(left, right);

        auto it = intervals.lower_bound(interval);

        if(!intervals.empty() && it != intervals.begin() && prev(it)->end >= interval.start) {
            --it;
            interval.start = min(it->start, interval.start);
        }

        while(it != intervals.end() && it->start <= interval.end) {
            interval.end = max(it->end, interval.end);
            intervals.erase(it++);
        }
        intervals.insert(interval);
    }

    bool queryRange(int left, int right) {
        Interval interval(left, right);

        int range = right - left;

        auto it = intervals.lower_bound(interval);

        if(!intervals.empty() && it != intervals.begin() && prev(it)->end > interval.start) {

            int common = min(interval.end, prev(it)->end) - interval.start;
            range -= common;
        }

        while(it != intervals.end() && it->start <= interval.end) {
            int common = min(interval.end, it->end) - it->start;
            range -= common;
            ++it;
        }

        return range == 0;
    }

    void removeRange(int left, int right) {
        Interval interval(left, right);

        auto it = intervals.lower_bound(interval);

        if(!intervals.empty() && it != intervals.begin() && prev(it)->end > interval.start)
            --it;

        while(it != intervals.end() && it->start < interval.end) {

            int common_start = max(interval.start, it->start);
            int common_end = min(interval.end, it->end);

            if(it->start < common_start)
                intervals.insert(Interval(it->start, common_start));

            if(it->end > common_end)
                intervals.insert(Interval(common_end, it->end));

            intervals.erase(it++);
        }
    }
};
