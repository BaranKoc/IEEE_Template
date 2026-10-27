class PeekingIterator : public Iterator {
public:
    int _nextVal;
    bool _hasNext;
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {

        _nextVal = 0;
        _hasNext = Iterator::hasNext();
        if (_hasNext)
            _nextVal = Iterator::next();
    }

    int peek() {
        return (_nextVal);
    }

    int next() {
        int tmp = _nextVal;

        _hasNext = Iterator::hasNext();
        if (_hasNext)
            _nextVal = Iterator::next();
        return (tmp);
    }

    bool hasNext() const {
        return (_hasNext);
    }
};
